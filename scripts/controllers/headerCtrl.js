angular.module('personalApp.controllers', [])
   .controller('HeaderController', ['$scope', '$state',
      	function($scope, $state) {
      		
      		$scope.isActive = function (state) {
        		return $state.is(state);
			}

		}
   ]); /* CONTROLLER FUCTION END */