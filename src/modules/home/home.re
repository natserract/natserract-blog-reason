
open Utils;
open ReduxUtils;
open Home_styles;

[@react.component]
let make = () => {
    let get_loading_state = useSelectorBool(state => state##fileSystemState##loading);
    let get_dir_state = useSelectorArray(state => state##fileSystemState##dir);
    let get_err_state = useSelectorString(state => state##fileSystemState##errors);
    let get_desc_state = useSelectorArray(state => state##fileSystemState##description);

    React.useEffect0(() => {
        dispatch("@@filesystem/LOAD");
        None
    });
    
    <Container>
        ( switch get_loading_state {
            | true => <span> "Loading" -> textEl </span>
            | false =>  
                <ul className=Styles.list>
                    {
                        get_dir_state
                            -> Belt.Array.mapWithIndex((i, item) => {
                                    let get_items = Js.String.make(item);
                                    let get_desc_by_index = Js.String.make(get_desc_state[i]);
                                
                                    <li key=(string_of_int(i))>
                                        <Link href=("/#/post/"++get_items)>get_items -> textEl</Link>
                                        <span className="abstract-description">
                                            get_desc_by_index -> textEl
                                        </span>
                                    </li>
                            })
                            -> React.array
                    }
                </ul>

            | _ => get_err_state -> textEl
        })
    </Container>
 
}

