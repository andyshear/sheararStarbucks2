#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Resources.h"
#include "Starbucks.h"
#include "sheararStarbucks2.h"

#include <iostream>
#include <fstream>


using namespace ci;
using namespace ci::app;
using namespace std;

class sheararHW4App : public AppBasic {
  public:
	int arrlength;
	int count;
	Entry* readFile();
	Entry* entries;
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();

private:
	sheararStarbucks2 ssb;
};

Entry* sheararHW4App::readFile(){
	
		
	
	ifstream in("../resources/Starbucks_2006.csv");
	if(!in){
		console()<<"Error in opening"<<endl;
	}


	arrlength = 1000;
	count = 0;
	//Referenced how JoshRuebusch used getline() to read in the .csv file for both of these while loops
	//Had a lot of trouble getting file to read in correctly
	while(!in.eof()){			
		string line, identifier_;
		double xin;
		double yin;
		getline(in,line,',');
		identifier_ = line;
		in >> xin;
		getline(in,line,',');
		in >> yin;
		//getline(in,line,'\r');
		count++;		
	}
	arrlength = count;
	count = 0;
	entries = new Entry[arrlength];
	ifstream inFile("../resources/Starbucks_2006.csv");


	while(count<arrlength){
		
		string line;
		string identifier_;
		double xin;
		double yin;
		
		getline(inFile,line,',');
		identifier_ = line;
		inFile >> xin;
		getline(inFile,line,',');
		inFile >> yin;
		//getline(inFile,line,'\r');

		(entries)[count].identifier = identifier_;
		(entries)[count].x = xin;
		(entries)[count].y = yin;
		count++;
		
	}
	return entries;
}


//format forked from regojr
void sheararHW4App::setup()
{
	console() << "Reading in locations..." << endl;
	Entry* entry = readFile();

	console() << "Building Grid..." << endl;
	ssb.build(entries, arrlength);	
	console() << "Build Complete." << endl;

	console() << "Running Closest Starbucks Algorithm..." << endl;
	Entry* closest = ssb.getNearest(0.1234567, 0.6234567); //ambiguous current location input for testing purposes

	console() << "Algorithm Complete. " << endl;

	console() << "Results Yielded		" << closest->identifier 
		<< "	as the closest Starbucks to your location." << endl;
}

void sheararHW4App::mouseDown( MouseEvent event )
{
}

void sheararHW4App::update()
{
}

void sheararHW4App::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_BASIC( sheararHW4App, RendererGl )
