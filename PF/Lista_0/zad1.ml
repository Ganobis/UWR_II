if true then 4 else 5  (*int = 4*);;
if false then 1 else 3.5  (*nie, wyrażenie ma typ float, a spodziewa się int*);;
4.75 + 2.34 (*nie, wyrażenie ma typ float, a spodziewa się int, działania na float musi mieć +.*);;
false || "ab">"cd" (*bool = false*);;
if true then () (*unit = ()*);;
if false then () else 4 (*nie, wyrażenie ma typ int, a spodziewa się unit*)
let x = 2 in x^"aa" (*nie zadziała bo 2 to int*)
let y = "abc" in y^y (*string = "abcabc"*)
(fun x -> x.[1]) "abcdef" (*char = 'b'*)
(fun x -> x) true (*bool = true*)
let x = [1;2] in x@x (*int list = [1; 2; 1; 2]*)
let rec f f = f+f in f 42 (*int = 84*)