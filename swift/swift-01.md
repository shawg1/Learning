####基础部分
====
########2017.11.09
#####常量和变量
```
let 声明常量->声明后其值不可变
var 声明变量->可改变
```
#####输出print()
```
print();
其中默认参数有:
separator:' ';
terminator:'\n';
这两个一个是分隔符,一个是结束符,可手动设置,注意设置的时候是用的:而不是=
```
#####类型别名
```
typealias AudioSample = UInt16

var max = AudioSample.min
//就和c++的typedef一样的
```
#####布尔值
```
let T = true
let F = false

if T
{
    ...
}
else{
    ...
}
//注意这个if后面必须要加bool,不可以用0和非0来代替
//if 1...这样子是报错的!!!
//写成if va == 1{...}这样子
```

#####元组
```
//声明一个http状态码

let http404Error = (404,"Not Found")

//支持结构赋值

let (statusCode,statusMessage) = http404Error
print("The status message is \(statusMessage)")
//注意,这是字符串插值的语法,用\()包裹一个变/常量名,然后字符串内容会自动填充该值
```
如果你只需要一部分元组值，分解的时候可以把要忽略的部分用下划线（_）标记
```
let (justTheStatusCode, _) = http404Error
print("The status code is \(justTheStatusCode)")
// 输出 "The status code is 404"
```
还可以通过下标来访问元组中的单个元素，下标从零开始
```
print("The status code is \(http404Error.0)")
// 输出 "The status code is 404"
print("The status message is \(http404Error.1)")
// 输出 "The status message is Not Found"
```
你可以在定义元组的时候给单个元素命名
```
let http200Status = (statusCode: 200, description: "OK")
```

元组中的元素命名后，你可以通过名字来获取这些元素的值
```
print("The status code is \(http200Status.statusCode)")
// 输出 "The status code is 200"
print("The status message is \(http200Status.description)")
// 输出 "The status message is OK"
```
#####nil
```
//swift有一种可选类型
//也就是会面临这样的需求和矛盾,需要把一个字符串转化为数字时,"123"=>123,"hello"=>就没有了
//这个时候,也就是在转化的时候会返回一种可选类型,在类型后面?表示
let possibleNumber = "123"
let convertedNumber = Int(possibleNumber)
//则convertedNumber类型就是int?或者是optional int含义是可能包含一个整数或者是nil


var serverResponseCode:Int? = 404
//让可选类型包含404
//swift会在创建变量的是后指定类型,:加类型是手动指定类型了
serverResponseCode = nil
//让可选类型不包含值
var surveyAnswer :String?
//自动设置为nil

//判断一个可选类型包不包含值,可以通过if进行
if convertedNumber != nil{
    print("convertedNumber contains some integer value.")
}
//当你确定可选类型确实包含值之后，你可以在可选的名字后面加一个感叹号（!）来获取值。这个惊叹号表示“我知道这个可选有值，请使用它。”这被称为可选值的强制解析（forced unwrapping）
if convertedNumber != nil {
    print("convertedNumber has an integer value of \(convertedNumber!).")
}
// 输出 "convertedNumber has an integer value of 123."
```
#####可选绑定
使用可选绑定（optional binding）来判断可选类型是否包含值
//如果包含就把值赋给一个临时常量或者变量。可选绑定可以用在 if 和 while 语句中，这条语句不仅可以用来判断可选类型中是否有值，同时可以将可选类型中的值赋给一个常量或者变量
```
if let actualNumber = Int(possibleNumber) {
    print("\'\(possibleNumber)\' has an integer value of \(actualNumber)")
} else {
    print("\'\(possibleNumber)\' could not be converted to an integer")
}
// 输出 "'123' has an integer value of 123"
if let firstNumber = Int("4"), let secondNumber = Int("42"), firstNumber < secondNumber && secondNumber < 100 {
    print("\(firstNumber) < \(secondNumber) < 100")
}
// 输出 "4 < 42 < 100"
```

还有异常处理和断言提及一些内容
仔细看了一下swift的语法,是抱着swift和python很像,我来找不同的心态看的
只看了基础的概述部分,感觉到我会的还是太少了,很多东西我都不是很懂,我不知道!
