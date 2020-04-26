/* access DOM */
[@bs.val] external document: Js.t({..}) = "document";

/* Markdown file */
[@bs.module]  external marked: (~param: string) => string = "marked" ;

/* Import file */
[@bs.val] external import: string => string = "require";

/* print string element */
let textEl: string => React.element = React.string;

/* localStorage */
type t;
[@bs.val] external localStorage: string => string = "localStorage.getItem";

/* JSON */
[@bs.val] external json_parse: string => array('a) = "JSON.parse";

/* Redux */
module ReduxUtils = {
    type t;

    [@bs.module "../store/helpers/functions.ts"] [@bs.scope ("getState")] external redux_store: unit = "";
    [@bs.module "../store/helpers/functions.ts"]  external dispatch: string => unit = "dispatch";

    [@bs.module "react-redux"] external useSelectorBool: (~state: Js.t('a) => unit) => bool = "useSelector";
    [@bs.module "react-redux"] external useSelectorArray: (~state: Js.t('a) => unit) => array('a) = "useSelector";
    [@bs.module "react-redux"] external useSelectorString: (~state: Js.t('a) => unit) => string = "useSelector";

    [@bs.module "react-redux"] external useDispatch: unit => unit = "useDispatch";
}

/* Array */
let find_unique_arr_value = [%raw "
    function(arr) {
        let t = new Set(arr);
        let val = t.values();
        return Array.from(val);
    }
"]