(*zad 2*)
let rec cycle list n = 
	  if n != (List.length list) then
	  	cycle ((List.tl list) @ [List.hd list]) (n+1)
	  else
	 	 list;;
(*
# cycle [1; 2; 3] 2;;
- : int list = [2; 3; 1]

# cycle ["a"; "ba"; "c"; "r"; "p"] 1;;
- : string list = ["p"; "a"; "ba"; "c"; "r"]
*)
