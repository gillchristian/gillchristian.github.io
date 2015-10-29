angular.module('personalApp.controllers')
   .controller('PortfolioController', ['$scope',
      	function($scope) {
      		$scope.projects = [
            {
              name: 'Poder Judicial, Entre Rios',
              description: 'WordPress plugins and theme edition, front end development.',
              url: 'http://www.jusentrerios.gov.ar/',
              img: 'assets/img/portfolio/jusentrerios.jpg',
              tags: ['WordPress','php', 'html5', 'ccs3']
            },
			{
              name: 'ADRA Central Asia Website',
              description: 'Creation of the website, using Wordpress template.',
              url: 'http://adra-central.asia/?lang=en',
              img: 'assets/img/portfolio/ADRAwebsite.jpg',
              tags: ['WordPress','php', 'html5', 'ccs3']
            }];
          
          $scope.personals = [
            {
              name: 'CPT Class',
              description: 'Helper class to create Custom Pots Types in WordPress.',
              url: 'https://github.com/gillchristian/CPT',
              img: 'assets/img/portfolio/cpt.jpg',
              tags: ['WordPress','php']
            },
			{
              name: 'Army Calculator',
              description: 'Troops amounts and costs calculator for Clash of Clans.',
              url: 'http://gillchristian.github.io/clash/',
              img: 'assets/img/portfolio/clash_app.jpg',
              tags: ['angularJS','bootstrap']
            }];

    	}
   ]);