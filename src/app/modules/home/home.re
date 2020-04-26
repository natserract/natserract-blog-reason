
open Utils;
open ReduxUtils;

[@react.component]
let make = () => {
    let loading_state = useSelectorBool(state => state##fileSystemState##loading);
    let dir_state = useSelectorArray(state => state##fileSystemState##dir);
    let err = useSelectorString(state => state##fileSystemState##errors);

    React.useEffect0(() => {
        dispatch("@@filesystem/LOAD");
        None
    });
    
    switch loading_state {
        | true => <span> "Loading" -> textEl </span>
        | false =>  
            <ul>
                {
                    dir_state
                        -> Belt.Array.mapWithIndex((i, item) => {
                                let get_items = Js.String.make(item);
                                <Link key=(string_of_int(i)) href=("/#/post/"++get_items)>get_items -> textEl</Link>
                        })
                        -> React.array
                }
            </ul>

        | _ => err -> textEl
    };
 
}