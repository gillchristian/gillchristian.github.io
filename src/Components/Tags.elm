module Components.Tags exposing (view)

import Html exposing (Html)


view : List String -> Html msg
view tags =
    Html.code
        []
        [ Html.text "[ "
        , Html.text <| String.join ", " tags
        , Html.text " ]"
        ]
