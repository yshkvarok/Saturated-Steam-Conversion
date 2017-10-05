public class NBody {
	public static void main(String[] args) {
		double T = Double.parseDouble(args[0]);
		double dt = Double.parseDouble(args[1]);
		String filename = args[2];
		In in = new In(filename);

		int numPlanets = in.readInt();
		double radius = in.readDouble();

		Planet[] planets = new Planet[numPlanets];

		for (int i = 0; i < planets.length; i++)
			planets[i] = getPlanet(in);

		StdDraw.setXscale(-radius, radius);
		StdDraw.setYscale(-radius, radius);
		StdDraw.picture(0, 0, "images/starfield.jpg");

		for (int i = 0; i < planets.length; i++)
			planets[i].draw();

		StdAudio.play("audio/2001.mid");

		for (int i = 0; i <= T; i += dt)
		{
			for (int j = 0; j < planets.length; j++)
			{
				planets[j].setNetForce(planets);
				planets[j].update(dt);
			}

			StdDraw.picture(0, 0, "images/starfield.jpg");
			for (int j = 0; j < planets.length; j++)
				planets[j].draw();

			StdDraw.show(10);
		}
	}

	public static Planet getPlanet(In input)
	{
		double x = input.readDouble();
		double y = input.readDouble();
		double xVel = input.readDouble();
		double yVel = input.readDouble();
		double m = input.readDouble();
		String file = input.readString();

		Planet p = new Planet(x, y, xVel, yVel, m, file);
		return p;
	}
}