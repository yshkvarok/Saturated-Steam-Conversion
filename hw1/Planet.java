public class Planet {
	public double x;
	public double y;
	public double xVelocity;
	public double yVelocity;
	public double mass;
	public String img;
	public double xNetForce;
	public double yNetForce;
	public double xAccel;
	public double yAccel;

	public Planet(double xPos, double yPos, double xCurrVelocity,
				double yCurrVelocity, double massValue, String imgFile) 
	{
		x = xPos;
		y = yPos;
		xVelocity = xCurrVelocity;
		yVelocity = yCurrVelocity;
		mass = massValue;
		img = imgFile;
		xNetForce = 0;
		yNetForce = 0;
		xAccel = 0;
		yAccel = 0;
	}

	public double calcDistance(Planet otherPlanet)
	{
		double dist = (otherPlanet.x - x);
		dist *= dist;
		dist += (otherPlanet.y - y) * (otherPlanet.y - y);
		dist = Math.sqrt(dist);
		return dist;
	}

	public double calcPairwiseForce(Planet otherPlanet)
	{
		double G = 6.67 * Math.pow(10, -11);

		double force = G * mass * otherPlanet.mass / ((otherPlanet.x - x)*(otherPlanet.x - x) + (otherPlanet.y - y)*(otherPlanet.y - y));
		return force;
	}

	public double calcPairwiseForceX(Planet otherPlanet)
	{
		double fx = calcPairwiseForce(otherPlanet);
		fx *= otherPlanet.x - x;
		fx /= Math.sqrt((otherPlanet.x - x)*(otherPlanet.x - x) + (otherPlanet.y - y)*(otherPlanet.y - y));

		return fx;
	}

	public double calcPairwiseForceY(Planet otherPlanet) 
	{
		double fy = calcPairwiseForce(otherPlanet);
		fy *= otherPlanet.y - y;
		fy /= Math.sqrt((otherPlanet.x - x)*(otherPlanet.x - x) + (otherPlanet.y - y)*(otherPlanet.y - y));
		return fy;
	}

	public void setNetForce(Planet[] planets)
	{
		double xNet = 0;
		double yNet = 0;
		for (int i = 0; i < planets.length; i++)
		{
			if (planets[i] != this)
			{
				xNet += this.calcPairwiseForceX(planets[i]);
				yNet += this.calcPairwiseForceY(planets[i]);
			}

		}

		xNetForce = xNet;
		yNetForce = yNet;
	}

	public void draw() 
	{
		StdDraw.picture(x, y, "images/" + img);
	}

	public void update(double dt)
	{
		xAccel = xNetForce / mass;
		yAccel = yNetForce / mass;

		xVelocity = xVelocity + dt * xAccel;
		yVelocity = yVelocity + dt * yAccel;

		x = x + dt * xVelocity;
		y = y + dt * yVelocity;
	}
}