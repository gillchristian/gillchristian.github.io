module Pages.Articles exposing (page)

import Components.Sidebar
import Components.Header exposing (Page(..))
import Html exposing (Html)
import View exposing (View)


page : View msg
page =
  Components.Sidebar.view
    Articles
    { page =
        { title = "Pages.Articles"
        , body = [ Html.text "/articles" ]
        }
    }
