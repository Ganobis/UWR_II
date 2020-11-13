(*zad1*)
let rec sublist list =
	match list with
	| [] -> [[]]
	| head::tail -> 
		let rest = sublist tail in
		let lista = List.map (fun x -> head::x) rest in lista @ rest;;
(*
# sublist [1; 2; 3; 4; 5];;
int list list =
[[1; 2; 3; 4; 5]; [1; 2; 3; 4]; [1; 2; 3; 5]; [1; 2; 3]; [1; 2; 4; 5];[1; 2; 4]; [1; 2; 5]; [1; 2]; [1; 3; 4; 5]; [1; 3; 4]; [1; 3; 5]; [1; 3];[1; 4; 5]; [1; 4]; [1; 5]; [1]; [2; 3; 4; 5]; [2; 3; 4]; [2; 3; 5]; [2; 3]; [2; 4; 5]; [2; 4]; [2; 5]; [2]; [3; 4; 5]; [3; 4]; [3; 5]; [3];[4; 5]; [4]; [5]; []]
 
string list list =
[["a"; "b"; "c"]; ["a"; "b"]; ["a"; "c"]; ["a"]; ["b"; "c"]; ["b"]; ["c"];[]]
*)