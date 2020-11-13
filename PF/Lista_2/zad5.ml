(*zad 5*)
let rec sufixes list =
	match list with
	| [] -> [[]]
	| head::tail -> let rest = sufixes tail in (list::rest);;

let rec prefixes list =
	match list with
	| [] -> [[]]
	| head::tail -> []::List.map (fun rest -> head::rest) (prefixes tail);;

(*
sufixes [1; 2; 3];;
- : int list list = [[1; 2; 3]; [2; 3]; [3]; []]
# prefixes [1; 2; 3];;
- : int list list = [[]; [1]; [1; 2]; [1; 2; 3]]
*)