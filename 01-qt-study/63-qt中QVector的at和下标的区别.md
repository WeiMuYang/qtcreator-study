# QVector中的at和下标以及data的区别  

## 1 QVetor的介绍    
- `QVector`类是一个提供动态数组的模板类。    
- `QVector<T>`是Qt的一个通用容器类。它将元素存储在相邻的内存位置，并提供基于索引的快速访问。    
- `QList<T>`、`QLinkedList<T>`、`QVector<T>`和`QVarLengthArray<T>`提供类似的api和功能。它们通常是可互换的，但也存在性能问题。下面是用例的概述：    
	1. QVector应该是您的默认首选。`QVector<T>`通常比`QList<T>`具有更好的性能，因为`QVector<T>`总是按顺序将其项存储在内存中，其中`QList<T>`将在堆上分配其项，除非`sizeof（T）<=sizeof（void*）`，并且T已使用`Q_DECLARE_TYPEINFO`声明为`Q_MOVABLE_类型`或`Q_基元类型`。请参阅使用QList的利弊以了解解释。    
	2. QList在整个qtapi中用于传递参数和返回值。使用QList与这些api接口。   
- 如果您需要一个真正的链表，它保证在中间列表中插入常量时间，并且对项使用迭代器而不是索引，请使用`QLinkedList`。    
- 注意：QVector和QVarLengthArray都保证了C兼容的数组布局。QList没有。如果应用程序必须与C API接口，这可能很重要。   
- 注意：只要引用的项保留在容器中，就可以使用指向QLinkedList的迭代器和对分配qlist的堆的引用。对于迭代器和对QVector的引用以及分配qlist的非堆，则不是这样。   

## 2 基本用法   
```C++
 QVector <int> intVec;
    for(int i = 0; i < 10; ++i)
        intVec.append(i + 1);
    qDebug() << "intVec.at(4) = " <<  intVec.at(4);
    qDebug() << "intVec[4] = " <<  intVec[4];
    // intVec.at(4) += 10;    // readonly  --error
    intVec[4] += 100;
    qDebug() << "intVec.at(4) = " <<  intVec.at(4);
    qDebug() << "intVec[4] = " <<  intVec[4];

    qDebug() << "length = " << intVec.length();
    intVec.insert(10,22);   // 最多可以在下标是length的位置插入
    qDebug() << "length = " << intVec.length();
    intVec.insert(11,22);   // 最多可以在下标是length的位置插入
    qDebug() << "length = " << intVec.length();
    // intVec.insert(15,22);   // insert: "index out of range" --error
```

## 3 其他用法   

1. QVector使用基于0的索引，就像C ++数组一样。要访问特定索引位置的项目，可以使用operator []（）。在非常量向量上，operator []（）返回对可在赋值左侧使用的项的引用：   
2. 对于**只读访问**，另一种语法是使用at（）：    
3. 访问存储在QVector中的数据的另一种方法是调用data（）。该函数返回指向向量中第一项的指针。您可以使用指针直接访问和修改存储在向量中的元素。如果需要将QVector传递给接受普通C ++数组的函数，则该指针也很有用。  
4. at（）可以比operator []（）更快，因为它永远不会导致深层复制。  


## 4 参考资料   
1. https://blog.csdn.net/qq_21449473/article/details/92803357   
