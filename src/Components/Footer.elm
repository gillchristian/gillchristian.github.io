module Components.Footer exposing (footer)

import Components.Social exposing (social)
import Html exposing (Html)
import Html.Attributes as Attr



-- TODO: get current year


footer : Html msg
footer =
    Html.footer [ Attr.class "footer" ]
        [ Html.div
            [ Attr.class "footer-social" ]
            [ social ]
        , Html.div
            [ Attr.class "footer-cr" ]
            [ Html.text "Christian Gill © 2024" ]
        ]
