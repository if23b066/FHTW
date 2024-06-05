describe("Find Spaceship", function () {
    beforeEach(function () {
        spaceship = new HelpAlf();
    });

	//Test #1
    let map = "..........\n..........\n..........\n..........\n..........\n..........";
    it("should return 'Spaceship lost forever.' for an empty map", function () {
        expect(spaceship.findSpaceship(map)).toEqual('Spaceship lost forever.');
    });

	//Test #2
    let map2 = "..........\n..........\n..........\n.......X..\n..........\n..........";
    it("should return 7,2 for a map with a spaceship", function () {
        expect(spaceship.findSpaceship(map2)).toEqual("7,2");
    });

    //Test #3
    let map3 = "..........\n..........\n..........\n..........\n..........\nX.........";
    it("should return 0,0 for a map with a spaceship at the bottom left corner", function () {
        expect(spaceship.findSpaceship(map3)).toEqual("0,0");
    });

	//Test #4
	let map4 = "..........\n..........\n..........\n..........\n..........\n........X.";
	it("should return 8,0 for a map with a spaceship", function () {
		expect(spaceship.findSpaceship(map4)).toEqual("8,0");
	});
});
