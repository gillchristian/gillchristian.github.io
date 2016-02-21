angular.module('personalApp', ['ui.router', 'personalApp.controllers'])

.config(function($stateProvider, $urlRouterProvider) {
   //
   // For any unmatched url, redirect to /state1
   $urlRouterProvider.otherwise("/");
   //
   // Now set up the states
   $stateProvider
      .state('home', {
         url: '/',
         templateUrl: 'templates/home.html'
      })
      .state('portfolio', {
         url: '/porfolio',
         templateUrl: 'templates/porfolio.html',
         controller: 'PortfolioController'
      });
})

.config(['$httpProvider', function($httpProvider) {
   $httpProvider.defaults.useXDomain = true;
   delete $httpProvider.defaults.headers.common['X-Requested-With'];
}])