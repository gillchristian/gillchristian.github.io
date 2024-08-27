module Components.Sidebar exposing (view)

import Components.Footer exposing (footer)
import Components.Header exposing (Page, header)
import Html exposing (Html)
import Html.Attributes as Attr
import View exposing (View)


view : Page -> { page : View msg } -> View msg
view currentPage { page } =
    { title = page.title
    , body =
        [ Html.div [ Attr.class "Site" ]
            [ nav currentPage
            , Html.div [ Attr.class "Site-content" ] page.body
            , footer
            ]
        ]
    }


nav : Page -> Html msg
nav page =
    Html.nav [ Attr.class "nav-wrapper" ]
        [ Html.h3
            [ Attr.class "nav-title" ]
            [ Html.a
                [ Attr.href "/"
                , Attr.class "header-link nav-logo"
                ]
                [ Html.div [ Attr.class "nav-avatar" ] []
                , Html.text "Christian Gill"
                ]
            ]
        , header page
        ]
