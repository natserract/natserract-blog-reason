
open Core.Models.Routes;

let appRoutesConfig = () => {
    let url = ReasonReactRouter.useUrl();
    let hash = url.hash |> Js.String.split("/");

    switch (hash) {
      | [|"", "post", slug |] => Post(slug)
      | [|""|] => Home
      | _ => NotFound
    };
}