# 设计模式（c++)
[一、单例模式](https://github.com/happyhk/WorkLearning/blob/master/DesignPattern/%E5%8D%95%E4%BE%8B%E6%A8%A1%E5%BC%8F.cpp)
主要说一下工厂模式：工厂模式主要分为简单工厂模式、工厂方法模式、抽象工厂模式，c++的工厂模式主要用到了虚函数。<br>
简单工厂模式：简单工厂模式有一个工厂，可以生产多个产品，包含两个接口，一个是产品类的，一个是工厂类的。
产品类需要有一个基类，基类中的具体产品实现需要是个纯虚函数，这样一来，产品的子类必须要重写具体的产品实现，实现不同的功能。
产品类封装完成后，还需要一个工厂类，工厂类对产品类再次封装，最终实现由一个工厂对象决定创建出哪一种产品类的实例。<br>
[简单工厂模式代码](https://github.com/happyhk/WorkLearning/blob/master/DesignPattern/%E7%AE%80%E5%8D%95%E5%B7%A5%E5%8E%82%E6%A8%A1%E5%BC%8F.cpp)
工厂方法模式：工厂方法模式有多个工厂，但是每个工厂对应一个产品，此时工厂类和产品类都有基类，并且都包含一个纯虚函数。<br>
[工厂方法模式代码](https://github.com/happyhk/WorkLearning/blob/master/DesignPattern/%E5%B7%A5%E5%8E%82%E6%96%B9%E6%B3%95%E6%A8%A1%E5%BC%8F.cpp)
抽象工厂模式：在工厂方法模式的基础上，如果一个工厂想要生产多个产品，就有了抽象工厂模式，抽象工厂模式提供了一个创建一系列相关或相互依赖对象的接口，而无需指定他们具体的类。抽象工厂模式其实是简单工厂模式和工厂方法模式的组合。<br>
[抽象工厂模式代码](https://github.com/happyhk/WorkLearning/blob/master/DesignPattern/%E6%8A%BD%E8%B1%A1%E5%B7%A5%E5%8E%82%E6%A8%A1%E5%BC%8F.cpp)
