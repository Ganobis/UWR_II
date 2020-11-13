
(*zad 3*)
(*
let lt1 = [2; 4; 6];;
val lt1 : int list = [2; 4; 6]
let lt2 = [1; 3; 5];;
val lt2 : int list = [1; 3; 5]
*)
let rec merge cmp list1 list2 =
	match (list1, list2) with
	| [], _ -> list2 
	| _, [] -> list1
	| (list1_head::list1_tail, list2_head::list2_tail) ->
		if cmp list1_head list2_head then
			list1_head::(merge cmp list1_tail list2)
		else
			list2_head::(merge cmp list1 list2_tail);;
(*
# merge (<=) lt1 lt2;;
- : int list = [1; 2; 3; 4; 5; 6]
*)
let merge_tail cmp list1 list2 = 
	let rec aux l1 l2 r1 =
		match (l1, l2) with
		| ([], []) -> r1
		| ([], head::tail) -> (aux [] tail (head::r1))
		| (head::tail, []) -> (aux tail [] (head::r1))
		| (l1_head::l1_tail, l2_head::l2_tail) ->
			if cmp l1_head l2_head then
				aux l1_tail l2 (l1_head::r1)
			else
				aux l1 l2_tail (l2_head::r1) in
	List.rev (aux list1 list2 []);;
(*
# merge_tail (<=) lt1 lt2;;
- : int list = [1; 2; 3; 4; 5; 6]
*)
(*
# let lt3 = [1; 2; 3; 4; 5; 6];;
val lt3 : int list = [1; 2; 3; 4; 5; 6]
*)
let halve list = 
    let rec aux l1 l2 acc = 
        match acc with 
        | [] | [_] -> (List.rev l1), l2
        | head::tail -> aux ((List.hd l2)::l1) (List.tl l2) (List.tl tail)
    in aux [] list list;;
(*
halve lt3;;
- : int list * int list = ([1; 2; 3], [4; 5; 6])
*)
(*
# let lt4 = [3; 6; 1; 8; 3; 2];;
val lt4 : int list = [3; 6; 1; 8; 3; 2]
*)
let rec mergesort cmp list = 
	match list with
	| [] -> list
	| _::[] -> list
	| _ ->
		let (l1, l2) = halve list in
			merge cmp (mergesort cmp l1) (mergesort cmp l2);;
(*
# mergesort (<=) lt4;;
- : int list = [1; 2; 3; 3; 6; 8]
*)
