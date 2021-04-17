# Qt中Tree相关的用法    

## 1 初始化树形视图   

```c++
void Widget::initTree() {
    // 1. 使用QTreeView的对应模型是: QStandardItemModel，建立模型
    QStandardItemModel* model = new QStandardItemModel(ui->treeView);
    // 2. 添加表头
    model->setHorizontalHeaderLabels(QStringList() << QStringLiteral("项目名") << QStringLiteral("信息"));
    // 3. 创建第一个条目
    QStandardItem* itemProject = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_Project")],QStringLiteral("项目"));
    // 4. 放到第一行
    model->appendRow(itemProject);
    // 5. 索引itemProject条目，在第1列，添加新的条目
    model->setItem(model->indexFromItem(itemProject).row(),1,new QStandardItem(QStringLiteral("项目信息说明")));
    // 6. 创建第二个条目
    QStandardItem* itemFolder = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_folder")],QStringLiteral("文件夹1"));
    // 7. 添加到itemProject，作为它的孩子
    itemProject->appendRow(itemFolder);
    // 8. 注意model是setItem，然而Item是setChild
    itemProject->setChild(itemFolder->index().row(),1,new QStandardItem(QStringLiteral("信息说明")));
    // 9. 创建第三个条目，添加到itemProject                 QIcon                               QString
    itemFolder = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_folder")],QStringLiteral("文件夹2"));
    itemProject->appendRow(itemFolder);
    // 10. 两层for循环添加组和频道
    for(int i = 0;i < 5; ++i){
        QStandardItem* itemgroup = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_group")],QStringLiteral("组%1").arg(i+1));
        itemFolder->appendRow(itemgroup);
        for(int j=0;j<(i+1);++j){
            QStandardItem* itemchannel = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_channel")],QStringLiteral("频道%1").arg(j+1));
            itemgroup->appendRow(itemchannel);
            itemgroup->setChild(itemchannel->index().row(),1,new QStandardItem(QStringLiteral("频道%1信息说明").arg(j+1)));
        }
    }
    // 11. 给第三个条目，添加一行属性
    itemProject->setChild(itemFolder->index().row(),1,new QStandardItem(QStringLiteral("文件夹2信息说明")));

    // 12. 以下类似不再赘述
    itemProject = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_Project")],QStringLiteral("项目2"));
    model->appendRow(itemProject);
    for(int i = 0;i < 3; ++i)   {
        itemFolder = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_folder")],QStringLiteral("项目2文件夹%1").arg(i+1));
        // 12.1 设置复选框
        itemFolder->setCheckable(true);
        itemFolder->setTristate(true);  // 用户可以在所有三种状态之间更改的三状态复选框
        QStandardItem* itemFolderDes = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_group")],QStringLiteral("文件夹%1组").arg(i+1));
        itemProject->appendRow(itemFolder);
        itemProject->setChild(itemFolder->index().row(),1,itemFolderDes);
        for(int j = 0;j < i+1; ++j)  {
             QStandardItem* item = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_dataItem")],QStringLiteral("项目%1").arg(j+1));
             item->setCheckable(true);
             itemFolder->appendRow(item);
        }
    }

    // 13. 只要项目的数据发生变化，就会发出此信号。  调用treeItemChanged槽函数
    connect(model,&QStandardItemModel::itemChanged,this,&Widget::treeItemChanged);

    // 14. 将创建的model给树形表赋值
    ui->treeView->setModel(model);
}
```

## 2 树形视图的常用操作   
### 2.1 查找根节点   
```C++
///
/// \brief 获取根部节点，即从属关系的可显示最上级，与invisibleRootItem不同
/// \param item
/// \return
///
QStandardItem* Widget::getTopParent(QStandardItem* item)
{
    QStandardItem* secondItem = item;
    while(item->parent()!= 0)
    {
        secondItem = item->parent();
        item = secondItem;
    }
    if(secondItem->index().column() != 0)
    {
         QStandardItemModel* model = static_cast<QStandardItemModel*>(ui->treeView->model());
         secondItem = model->itemFromIndex(secondItem->index().sibling(secondItem->index().row(),0));
    }
    return secondItem;
}
///
/// \brief 获取父节点
/// \param itemIndex
/// \return
///
QModelIndex Widget::getTopParent(QModelIndex itemIndex)
{
    QModelIndex secondItem = itemIndex;
    while(itemIndex.parent().isValid())
    {
        secondItem = itemIndex.parent();
        itemIndex = secondItem;
    }
    if(secondItem.column() != 0)
    {
         secondItem = secondItem.sibling(secondItem.row(),0);
    }
    return secondItem;
}

```
### 2.2 节点点击事件   
```c++
///
/// \brief 树状视图的单击事件
/// \param index：当前点击的节点
///
void Widget::on_treeView_clicked(const QModelIndex &index)
{
    QString str;
    str += QStringLiteral("当前选中：%1\nrow:%2,column:%3\n").arg(index.data().toString())
            .arg(index.row()).arg(index.column());
    str += QStringLiteral("父级：%1\n").arg(index.parent().data().toString());
    // 是否是兄弟节点测试
    QString name,info;
    if(index.column() == 0)
    {
        name = index.data().toString();
        info = index.sibling(index.row(),1).data().toString();
    }
    else
    {
        name = index.sibling(index.row(),0).data().toString();
        info = index.data().toString();
    }
    str += QStringLiteral("名称：%1\n信息：%2\n").arg(name).arg(info);
    //寻找顶层
    QString top = getTopParent(index).data().toString();
    str += QStringLiteral("顶层节点名：%1\n").arg(top);
    ui->label_realTime->setText(str);
}
```

### 2.3 节点的选中事件   

```c++
///
/// \brief 如果选中的
/// \param item
///
void Widget::treeItemChanged(QStandardItem * item)
{
    if(item == nullptr)
        return;
    if(item->isCheckable())
    {
        //如果条目是存在复选框的，那么就进行下面的操作
        Qt::CheckState state = item->checkState();//获取当前的选择状态
        if(item->isTristate())
        {
            //如果条目是三态的，说明可以对子目录进行全选和全不选的设置
            if(state != Qt::PartiallyChecked)
            {
                //当前是选中状态，需要对其子项目进行全选
                treeItem_checkAllChild(item,state == Qt::Checked ? true : false);
            }
        }
        else
        {
            //说明是两态的，两态会对父级的三态有影响
            //判断兄弟节点的情况
            treeItem_CheckChildChanged(item);
        }
    }
}
///
/// \brief 递归设置所有的子项目为全选或全不选状态
/// \param item 当前项目
/// \param check true时为全选，false时全不选
///
void Widget::treeItem_checkAllChild(QStandardItem * item, bool check)
{
    if(item == nullptr)
        return;
    int rowCount = item->rowCount();
    for(int i=0;i<rowCount;++i)
    {
        QStandardItem* childItems = item->child(i);
        treeItem_checkAllChild_recursion(childItems,check);
    }
    if(item->isCheckable())
        item->setCheckState(check ? Qt::Checked : Qt::Unchecked);
}
void Widget::treeItem_checkAllChild_recursion(QStandardItem * item,bool check)
{
    if(item == nullptr)
        return;
    int rowCount = item->rowCount();
    for(int i=0;i<rowCount;++i)
    {
        QStandardItem* childItems = item->child(i);
        treeItem_checkAllChild_recursion(childItems,check);
    }
    if(item->isCheckable())
        item->setCheckState(check ? Qt::Checked : Qt::Unchecked);
}


///
/// \brief 测量兄弟节点的情况，如果都选中返回Qt::Checked，都不选中Qt::Unchecked,不完全选中返回Qt::PartiallyChecked
/// \param item
/// \return 如果都选中返回Qt::Checked，都不选中Qt::Unchecked,不完全选中返回Qt::PartiallyChecked
///
Qt::CheckState Widget::checkSibling(QStandardItem * item)
{
    //先通过父节点获取兄弟节点
    QStandardItem * parent = item->parent();
    if(nullptr == parent)
        return item->checkState();
    int brotherCount = parent->rowCount();
    int checkedCount(0),unCheckedCount(0);
    Qt::CheckState state;
    for(int i=0;i<brotherCount;++i)
    {
        QStandardItem* siblingItem = parent->child(i);
        state = siblingItem->checkState();
        if(Qt::PartiallyChecked == state)
            return Qt::PartiallyChecked;
        else if(Qt::Unchecked == state)
            ++unCheckedCount;
        else
            ++checkedCount;
        if(checkedCount>0 && unCheckedCount>0)
            return Qt::PartiallyChecked;
    }
    if(unCheckedCount>0)
        return Qt::Unchecked;
    return Qt::Checked;
}
///
/// \brief 根据子节点的改变，更改父节点的选择情况
/// \param item
///
void Widget::treeItem_CheckChildChanged(QStandardItem * item)
{
    if(nullptr == item)
        return;
    Qt::CheckState siblingState = checkSibling(item);
    QStandardItem * parentItem = item->parent();
    if(nullptr == parentItem)
        return;
    if(Qt::PartiallyChecked == siblingState)
    {
        if(parentItem->isCheckable() && parentItem->isTristate())
            parentItem->setCheckState(Qt::PartiallyChecked); // 局部选中
    }
    else if(Qt::Checked == siblingState)
    {
        if(parentItem->isCheckable())
            parentItem->setCheckState(Qt::Checked);
    }
    else
    {
        if(parentItem->isCheckable())
            parentItem->setCheckState(Qt::Unchecked);
    }
    treeItem_CheckChildChanged(parentItem);
}


```




## 3 参考资料  
1. https://blog.csdn.net/czyt1988/article/details/18996407    