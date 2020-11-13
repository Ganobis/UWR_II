let zero f x = x;;

let succ y (f: 'a -> 'a) (x: 'a) = f (y f x);;

let add y (z : ('a -> 'a) -> 'a -> 'a) f x : 'a = y f (z f x);;

let mul y (z : ('a -> 'a) -> 'a -> 'a) f : 'a -> 'a = y (z f);;

let is_zero (y : ('a -> 'a) -> 'a -> 'a) f g = y (fun _ -> g) f;;

let rec cnum_of_int n =
	if n <= 0
	then zero
	else succ (cnum_of_int (n - 1));;

let int_of_cnum cn : int = cn ((+)1) 0;; 