# QObject::connect: Cannot queue arguments of type 'QString&'的解决方法    

## 1 问题描述   
- 在主线程和子线程中，通过信号与槽发送QString，遇到   

```
QObject::connect: Cannot queue arguments of type 'QString&'
```

## 2 原内容描述   
```
it is not allowed to pass non-const value across threads.
that means you can’t modify the argument ‘s value across threads.
★Solution: add const before argument’s type
```

```
不允许跨线程传递非常量值。   
这意味着您不能跨线程修改参数的值。  
★解决方案：在参数类型前加常量  
```

## 3 参考资料   
1. https://blog.csdn.net/hp_cpp/article/details/82116807    