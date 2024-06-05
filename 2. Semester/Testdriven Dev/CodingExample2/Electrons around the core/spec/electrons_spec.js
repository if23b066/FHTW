describe('Electrons around the core', function() {
	beforeEach(function() {
		electrons = new ElectronsGame();
	});

	// Test #1
	it('should return 6 for the given array [1, 2, 3, 4, 5]', function() {
		let array = [1, 2, 3, 4, 5];
		expect(electrons.dice(array)).toEqual(6);
	});

	// Test #2
	it('should return 4 for the given array [2, 2, 3, 3]', function() {
		let array = [2, 2, 3, 3];
		expect(electrons.dice(array)).toEqual(4);
	});

	// Test #3
	it('should return 0 for the given array [6, 6, 4, 4, 1, 3] ', function() {
		let array = [6, 6, 4, 4, 1, 3];
		expect(electrons.dice(array)).toEqual(2);
	});

	// Test #4
	it('should return 0 for the given array [3, 5, 3, 5, 4, 2]', function() {
		let array = [3, 5, 3, 5, 4, 2];
		expect(electrons.dice(array)).toEqual(12);
	});
});
