(*fun x -> x ma typ wyrażenia x, let iditn x = x + x - x*)
let fun1a f g = fun x -> f (g x);;
let fun1b x y = x;;
let fun1c a b = if true then a else b;;
(*zad 2*)
let fun2 x = List.hd []

(*zad 3*)
let hd s = s 0;;
let tl s x = s (x+1);;
let add s a = fun x -> (s x) + a;;
let map s f = fun x -> f (s x);;
let map2 s1 s2 f = fun x -> f (s1 x) (s2 x);;
let replace s x n = fun x -> if x mod n == 0 then x else (s x);;
let take s n = fun x -> (s (n * x));;
let rec scan s f a n = if n > 0 then f (scan s f a (n-1)) (s n) else f a 0;;
let rec tabulate s ?x:(x=0) y = if x > y then [] else [(s x)] @ (tabulate s ~x:(x+1) y);;

(*TEST:
	# let f1 x = x * x;;
	# let f2 x = x + x;;
	# let f3 x y = x + y;;
-hd
	hd f2;;
	- : int = 0
-tl
	# tl f2 4;;
	- : int = 10
-add
	# let fp1 = add f1 10;;
	# fp1 1;;
	- : int = 11
	# fp1 2;;
	- : int = 14
-map
	# map f1 f2 4;;
	- : int = 32 (bo, f2(f1(4)) = f2(16) = 32)
-map2
	# map2 f1 f2 f3 10;;
	- : int = 120 (bo, f3(f1(10), f2(10) = f3(100, 20) = 120)
-replace
	#let fp2 = replace f1 11 2;; (zamienia wszystkie parzyste potęgi na 11)
	# fp2 1;;
	- : int = 1
	# fp2 2;;
	- : int = 11
	# fp2 3;;
	- : int = 9
	# fp2 4;;
	- : int = 11
-take
	# let fp3 = take f2 10;;
	# fp3 1;;
	- : int = 20
	# fp3 10;;
	- : int = 200
-scan
	# scan f1 f3 1 1;;
	- : int = 2  (bo, f3([f3 1 (f1 0)] (f1 1)) = f3([f3 1 0] 1) = f3 1 1 = 2)
	# scan f1 f3 2 2;;
	- : int = 7
-tabulate
	# tabulate f1 20;;
	- : int list =
	[0; 1; 4; 9; 16; 25; 36; 49; 64; 81; 100; 121; 144; 169; 196; 225; 256; 289;
	# tabulate f2 ~x:11 20;;
	- : int list = [22; 24; 26; 28; 30; 32; 34; 36; 38; 40]
*)

(*zad 4*)
let ctrue = fun a b -> if true then a else b;;
(*# val cfalse : 'a -> 'a -> 'a = <fun>*)
let cfalse = fun a b -> if false then a else b;;
(*# val cfalse : 'a -> 'a -> 'a = <fun>*)
let cand (x: 'a) (y: 'a) = if x == ctrue && y == ctrue then (ctrue: 'a) else (cfalse: 'a);;
(*# val cand : ('a -> 'a -> 'a) -> ('a -> 'a -> 'a) -> 'a -> 'a -> 'a = <fun>*)
let cor (x: 'a) (y: 'a) = if x == ctrue || y == ctrue then (ctrue: 'a) else (cfalse: 'a);;
(*# val cor : ('a -> 'a -> 'a) -> ('a -> 'a -> 'a) -> 'a -> 'a -> 'a = <fun>*)
let cbool_of_bool x = if x == true then (ctrue: 'a) else (cfalse: 'a);;
(*# val cbool_of_bool : bool -> 'a -> 'a -> 'a = <fun>*)
let bool_of_cbool x = if x == ctrue then true else false;;
(*# val bool_of_cbool : ('a -> 'a -> 'a) -> bool = <fun>*)

(*zad 5*)
let zero (f: 'a -> 'a) (x: 'a) = x;;