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

module ReduxUtils = {
    [@bs.module "../redux/helpers/functions.ts"] [@bs.scope ("getState")] external store: unit = "";
    [@bs.module "../redux/helpers/functions.ts"] [@bs.scope ("dispatch")] external dispatch: unit = "";
}