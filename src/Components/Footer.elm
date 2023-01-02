module Components.Footer exposing (footer)

import Html exposing (Html)
import Html.Attributes as Attr
import Components.Social exposing (social)


-- TODO: get current year
footer : Html msg
footer =
     Html.footer [ Attr.class "footer" ]
        [ Html.div
            [ Attr.class "footer-social" ]
            [ social ]
        , Html.div
            [ Attr.class "footer-cr" ]
            [ Html.text "Christian Gill © 2023" ]
        ]
