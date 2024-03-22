(* Author: Martha Kosa *)
(* 2-stack PDA implementations by XXX and YYY *)

(*********************)
(* basic stack ADT in OCaml *)
let push x s = x::s;;
		
let peek (h::_) = h;;
		
let pop s =
  match s with
    | _::t -> t;;
		
let is_empty s = (s = []);;
let is_not_empty s = (s != []);;
(*********************)

(* 1-stack PDA in OCaml *)

(* sample 1-stack PDA to accept {a^n b^n | n >= 0} *)
	
let anbn_alphabet = ['a'; 'b'];;
(* let num_states = 3;;*)
let anbn_final_states = [0; 1];;

let anbn_t0 = [(0, [], ['x']); (1, ['x'], [])];;
let anbn_t1 = [(2, [], []); (1, ['x'], [])];;
let anbn_t2 = [(2, [], []); (2, [], [])];;

let all_anbn_transitions = [anbn_t0; anbn_t1; anbn_t2];;

let anbn_PDA = (anbn_alphabet, all_anbn_transitions, anbn_final_states);;

(*********************)
(* utility functions *)

(* tail-recursive linear search in a list: -1 returned if item not found, 0-based otherwise *)
let position x list = 
  let rec accpos i y list =
    match list with
      | [] -> -1
      | z::t -> if y = z then i else (accpos (i+1) y t)
  in (accpos 0 x list);;

(* membership function *)
(* let rec belongs_to x list =
 *	match list with
 *		| [] -> false
 *		| y::t -> x = y || (belongs_to x t);;
*)

(* improved membership function *)
let belongs_to x list = (position x list) >= 0;;

(* converts from String to list of chars *)
(* from https://caml.inria.fr/mantis/view.php?id=5367 *)
let explode s =
  let rec exp i l =
    if i < 0 then l else exp (i - 1) (s.[i] :: l) in
    exp (String.length s - 1) [];;

(* find_transition will work for both 1-stack and 2-stack PDAs *)	
let find_transition state symbol alphabet all_transitions =
  let symbol_pos = (position symbol alphabet) in
    List.nth (List.nth all_transitions state) symbol_pos;;

(* last_config will work for both 1-stack and 2-stack PDAs *)	
let last_config config_list = List.nth config_list ((List.length config_list) - 1);;

(*********************)
(* 1-stack PDA simulator *)
(* an initial configuration is a 3-tuple consisting of the start state, the input string information, and one empty stack *)		
(* let init_one_stack_config = (0, ['a'; 'a'; 'b'; 'b'], []);; *)
let init_one_stack_config list = (0, list, []);;

(* checking for acceptance at end *)		
(* let is_configuration_accepting config final_states =
 *	match config with
 *		| (i, w, s) -> (belongs_to i final_states) && (is_empty w) && (is_empty s);;
*)

(* improved checking for acceptance at end *)		
let is_one_stack_config_accepting (i, w, s) final_states = (belongs_to i final_states) && (is_empty w) && (is_empty s);;

(* could the machine finish? *)
let is_one_stack_config_complete (i, w, s) = is_empty w;;

(* run_one_stack_pda produces a list of configurations *)
(* Ocaml has short-circuit evaluation with && and || - no need to evaluate y in false && y and true || y *)
let rec run_one_stack_pda (i, w, s) (a, t, f) tr = (* a - alphabet, t - all_transitions, f - final_states, tr - trace *)
  (* @ is list append *)
  match w with
    | [] -> tr@[(i, w, s)] 
    | hd::tl -> let what_to_do = (find_transition i hd a t) in
          match what_to_do with
            (* no change to stack *)
            | (j, [], []) ->
                run_one_stack_pda (j, tl, s) (a, t, f) (tr@[(i, w, s)])
            (* push only *)
            | (j, [], [p]) ->
                run_one_stack_pda (j, tl, (push p s)) (a, t, f) (tr@[(i, w, s)])
            (* pop only *)
            | (j, [top], []) ->
                if (is_not_empty s) && (peek s) = top then
                  run_one_stack_pda (j, tl, (pop s)) (a, t, f) (tr@[(i, w, s)])
                else
                  tr@[(i, w, s)] (* stop early - cannot proceed *)
            (* mixture of pushing and popping *)
            | (j, [top], [p]) ->
                if (is_not_empty s) && (peek s) = top then
                  run_one_stack_pda (j, tl, (push p (pop s))) (a, t, f) (tr@[(i, w, s)])
                else
                  tr@[(i, w, s)] (* stop early - cannot proceed *)
            | _ -> tr@[(i, w, s)];; (* could not find transition - cannot proceed *)										

let belongs_to_one_stack_lang input_list (a, t, f) =
  is_one_stack_config_accepting
    (last_config (run_one_stack_pda (init_one_stack_config input_list) (a, t, f) [])) f;;

let is_valid_one_stack_lang_string s (a, t, f) =
  belongs_to_one_stack_lang (explode s) (a, t, f);;

(*********************)

(*********************)
(* Testing of various functions and 1-stack PDA simulation *)

belongs_to_one_stack_lang [] anbn_PDA;;

belongs_to_one_stack_lang ['a'] anbn_PDA;;

belongs_to_one_stack_lang ['a'; 'b'] anbn_PDA;;

belongs_to_one_stack_lang ['a'; 'a'; 'b'; 'b'] anbn_PDA;;

belongs_to_one_stack_lang ['a'; 'a'; 'b'] anbn_PDA;;

let init_ab = init_one_stack_config ['a';'b'];;

find_transition 0 'a' anbn_alphabet all_anbn_transitions;;

find_transition 0 'b' anbn_alphabet all_anbn_transitions;;

position 'b' anbn_alphabet;;

run_one_stack_pda init_ab anbn_PDA [];;

(* position is a polymorphic function *)
position 5 [4;5;3];;
position 3 [4;5;3];;
position 6 [4;5;3];;
position 'c' anbn_alphabet;;

let s = push 'a' [];;
(peek s) = 'a';;

explode "";;

explode "aab";;

is_valid_one_stack_lang_string "" anbn_PDA;;

is_valid_one_stack_lang_string "a" anbn_PDA;;

is_valid_one_stack_lang_string "ab" anbn_PDA;;

is_valid_one_stack_lang_string "aabb" anbn_PDA;;

is_valid_one_stack_lang_string "aab" anbn_PDA;;

let s1 = push "Eric" [];;

push "Logan" (push "Eric" []);;

let s2 = push "Logan" s1;;

push "Michael" (push "Logan" (push "Eric" []));;

let s3 = push "Michael" s2;;

s3;;

let s3 = push "Michael" (push "Logan" (push "Eric" []));;

peek s1;;
peek s2;;
peek s3;;

let ints1 = push 42 (push 76 (push 37 []));;

peek ints1;;

pop ints1;;


