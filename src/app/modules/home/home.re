
open Home_styles;

[@react.component]
let make = () => {
    let read_dir = "dirs"
        -> Utils.localStorage
            -> Utils.json_parse;
   
    <div className="article-detail">
        <ul>
        ( read_dir
            -> Belt.Array.mapWithIndex((i, item) => {
                <Link key=(string_of_int(i)) href=("/#/post/"++item)>item -> Utils.textEl</Link>
            })   
            -> React.array
        )
        </ul>
    </div>    
}