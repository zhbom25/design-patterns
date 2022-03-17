#include "Singleton.h"
#include "Strategy.h"
#include "Observer.h"
#include "Adapter.h"
#include "Composite.h"
#include "Factory.h"
#include "Template.h"

int main() {
    // 测试单例模式
    Singleton* singleton1 = Singleton::getInstance();
    Singleton* singleton2 = Singleton::getInstance();
    singleton1->set(1,101);
    singleton1->set(2,102);
    singleton2->set(3,103);
    singleton1->print();
    singleton2->print();
    Singleton::destroy();

    // 测试策略模式
    Context* context = new Context(new OperationAdd());
    cout << context->doOperation(10,5) << endl;
    context = new Context(new OperationSub());
    cout << context->doOperation(10,5) << endl;
    context = new Context(new OperationMulti());
    cout << context->doOperation(10, 5) << endl;
    delete context;

    // 测试观察者模式
    Subject* subject = new Subject();
    BinaryObserver* binaryObserver = new BinaryObserver(subject);
    OctalObserver* octalObserver = new OctalObserver(subject);
    HexaObserver* hexaObserver = new HexaObserver(subject);
    cout << "set state = 5" << endl;
    subject->setState(5);
    cout << "set state = 10" << endl;
    subject->setState(10);
    delete(subject);

    // 测试适配器
    AudioPlayer* audioPlayer = new AudioPlayer();
    audioPlayer->play("mp3", "beyond the horizon.mp3");
    audioPlayer->play("mp4", "alone.mp4");
    audioPlayer->play("vlc", "far far away.vlc");
    audioPlayer->play("avi", "mind me.avi");
    delete(audioPlayer);

    // 测试组合模式
    CompositePatternDemo* compositePatternDemo = new CompositePatternDemo();
    compositePatternDemo->exec();
    delete(compositePatternDemo);

    // 测试工厂模式
    AbstractFactoryPatternDemo* demo = new AbstractFactoryPatternDemo();
    demo->exec();
    delete(demo);

    // 测试模版
    GameDemo* game = new GameDemo();
    game->exec();
    delete(game);

    return 0;
}
