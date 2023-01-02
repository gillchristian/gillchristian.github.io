module Pages.About exposing (page)

import Components.Sidebar
import Components.Header exposing (Page(..))
import Html exposing (Html)
import View exposing (View)


page : View msg
page =
  Components.Sidebar.view
    About
    { page =
        { title = "Pages.About"
        , body = [ Html.text "/about" ]
        }
    }
