# qt界面设计-StyleSheet以及QSS语法规则   

[toc]

- [主要参考](https://www.cnblogs.com/bclshuai/p/9809679.html)   
- 对于Pushbutton相关的控件， 要想使背景色生效，必须要设置一下某个border属性，border-color、border-width等等任何一个跟border相关的属性都行。因为pushbutton的原生边界把背景色给覆盖住了。   
- 在设置某个控件时，可以先搜一下，该控件有哪些QSS属性可以设置   

- 常用的设置模板   

```CSS
#combobox{     
    background-color: rgb(54, 98, 180);    	/*  背景色   */
	border:2px solid #00ffff; 				/*  边框设置  */
    	/* border必须有， background-color才能生效  */
	color:#ffffff;                      	/*  字体颜色  */  
    font-size: 12px;                     	/*  字体大小 */ 
    font-family: 微软雅黑;					 /*  字体 */ 
    padding:1px 1px 1px 3px;           	    /*  内边框：上右下左  */
	border-radius:10px;               		/*  四个角的弧度半径  */
    border-style: flat;						/*  扁平化  */
    text-align:center                       /*  对齐方式： left，right，center  */
} 


```



### 1 常用属性  
### 1.1 背景属性  
1. background：在一个声明中设置所有的背景属性。  
2. background-attachment：设置背景图像是否固定或者随着页面的其余部分滚动。  
3. background-color：设置元素的背景颜色。  
4. background-image：设置元素的背景图像。  
5. background-position：设置背景图像的开始位置  。  
6. background-repeat：设置是否及如何重复背景图像。  
7. background-clip：规定背景的绘制区域。  
8. background-origin: 规定背景图片的定位区域。  
9. background-size: 规定背景图片的尺寸。  

### 1.2 边框属性  
1. border: 在一个声明中设置所有的边框属性。  
2. border-bottom:在一个声明中设置所有的下边框属性。  
3. border-bottom-color: 设置下边框的颜色。  
4. border-bottom-style:设置下边框的样式。  
5. border-bottom-width:设置下边框的宽度。  
6. border-color:设置四条边框的颜色。  
7. border-left:在一个声明中设置所有的左边框属性。  
8. border-left-color:设置左边框的颜色。  
9. border-left-style:设置左边框的样式。  
10. border-left-width: 设置左边框的宽度。  
11. border-right: 在一个声明中设置所有的右边框属性。  
12. border-right-color:  设置右边框的颜色。  
13. border-right-style: 设置右边框的样式。  
14. border-right-width: 设置右边框的宽度。  
15. border-style: 设置四条边框的样式。  
16. border-top:在一个声明中设置所有的上边框属性。  
17. border-top-color:设置上边框的颜色。  
18. border-top-style:设置上边框的样式。  
19. border-top-width:设置上边框的宽度。   
20. border-width:设置四条边框的宽度。  
21. outline: 在一个声明中设置所有的轮廓属性。  
22. outline-color: 设置轮廓的颜色。  
23. outline-style:设置轮廓的样式。  
24. outline-width:设置轮廓的宽度。  
25. border-bottom-left-radius:定义边框左下角的形状。  
26. border-bottom-right-radius:定义边框右下角的形状。  
27. border-image:简写属性，设置所有 border-image-\* 属性。  
28. border-image-outset:规定边框图像区域超出边框的量。  
29. border-image-repeat:图像边框是否应平铺  (repeated)、铺满(rounded)或拉伸(stretched)。  
30. border-image-slice:规定图像边框的向内偏移。  
31. border-image-source:规定用作边框的图片。  
32. border-image-width:规定图片边框的宽度。  
33. border-radius:简写属性，设置所有四个 border-\*-radius 属性。  
34. border-top-left-radius:定义边框左上角的形状。  
35. border-top-right-radius:定义边框右下角的形状。  
36. box-decoration-break:  
37. box-shadow:向方框添加一个或多个阴影。  

### 1.3 字体属性  
1. font：在一个声明中设置所有字体属性。  
2. font-family：规定文本的字体系列。  
3. font-size：规定文本的字体尺寸。  
4. font-size-adjust：为元素规定 aspect 值。  
5. font-stretch：收缩或拉伸当前的字体系列。  
6. font-style：规定文本的字体样式。  
7. font-variant：规定是否以小型大写字母的字体显示文本。  
8. font-weight：规定字体的粗细。  

### 1.4 外边距属性（Margin）  
1. margin：在一个声明中设置所有外边距属性。  
2. margin-bottom：设置元素的下外边距。  
3. margin-left：设置元素的左外边距。  
4. margin-right：设置元素的右外边距。  
5. margin-top：设置元素的上外边距。  

### 1.5 内边距属性（Padding）    
1. padding：在一个声明中设置所有内边距属性。  
2. padding-bottom：设置元素的下内边距。  
3. padding-left：设置元素的左内边距。  
4. padding-right：设置元素的右内边距。  
5. padding-top：设置元素的上内边距。  

### 1.6 文本属性（Text）  
1. color：设置文本的颜色。   
2. direction：规定文本的方向 / 书写方向。  
3. letter-spacing：设置字符间距。  
4. line-height：设置行高。  
5. text-align：规定文本的水平对齐方式。  
6. text-decoration：规定添加到文本的装饰效果。  
7. text-indent：规定文本块首行的缩进。  
8. text-shadow：规定添加到文本的阴影效果。  
9. text-transform：控制文本的大小写。  
10. unicode-bidi：设置文本方向。  
11. white-space：规定如何处理元素中的空白。  
12. word-spacing：设置单词间距。  
13. hanging-punctuation：规定标点字符是否位于线框之外。  
14. punctuation-trim：规定是否对标点字符进行修剪。  
15. text-align-last：设置如何对齐最后一行或紧挨着强制换行符之前的行。  
16. text-emphasis：向元素的文本应用重点标记以及重点标记的前景色。  
17. text-justify：规定当 text-align 设置为 "justify" 时所使用的对齐方法。  
18. text-outline:规定文本的轮廓。  
19. text-overflow:规定当文本溢出包含元素时发生的事情。  
20. text-shadow:向文本添加阴影。  
21. text-wrap:规定文本的换行规则。  
22. word-break:规定非中日韩文本的换行规则。  
23. word-wrap:允许对长的不可分割的单词进行分割并换行到下一行。  





## 2 参考资料   
1. https://blog.csdn.net/lywzgzl/article/details/41488281   
2. https://blog.csdn.net/yansmile1/article/details/52936182   
3. https://blog.csdn.net/xuhongtao123459/article/details/5875614   
4. https://blog.csdn.net/qq_37631516/article/details/104911449  
5. https://blog.csdn.net/wzz953200463/article/details/102925629  