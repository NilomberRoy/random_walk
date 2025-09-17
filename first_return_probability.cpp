#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;
std::random_device r;
std::seed_seq seed{r(), r(), r(), r(), r()};
std::mt19937 gen(seed);

int N;
int E;
int filenum;
vector<int> step;
vector<long double> f;

string firstreturn;


void seed_generator() {
	auto now = system_clock::now();
	auto duration = now.time_since_epoch();
	auto seed_value = duration.count();
	gen.seed(seed_value);
}

void first_return() {

	ofstream file(firstreturn);

	for(int en=1; en<=E; en++) {
		f.resize(N/2+1,0.0);
		for(int n=2; n<=N; n+=2) {
			int first_return_count = 0; // Initialize count for first returns to zero
			for(int walks=1; walks<=pow(2,n); walks++) {
				seed_generator();
				step.resize(n+1,0);
				int position_at_zero = 0;

				for(int i=1; i<=n; i++) {
					step[0]=0;

					uniform_real_distribution<long double> random(0,1);
					long double random_number = random(gen);


					if(random_number <= 0.5) {

						step[i]=step[i-1] - 1;

						if(i ==n && step[i] == 0) {
							position_at_zero++;

						} else if(step[i]== 0) {
							break;
						}
					} else if(random_number > 0.5) {

						step[i] =step[i-1] + 1;

						if(i == n && step[i] == 0) {
							position_at_zero++;

						} else if(step[i]== 0) {
							break;
						}
					}

				}

				if (position_at_zero == 1) {
					first_return_count++; // Increment count for first returns to zero
				}
				//cout<<"first_return_count "<<first_return_count<<endl;
				step.clear();

			}
			f[n/2]+=(long double)(first_return_count/(E*pow(2,n)));
		}

		cout<<"ensem "<<en<<" ok"<<endl;
	}
	for(int i=2; i<=N; i+=2) {
		cout<<setprecision(10)<<i/2<<"  "<<setprecision(10)<<(double)log(i/2)<<"  "<<setprecision(10)<<(double)log((double)(f[i/2]))<<"  "<<setprecision(10)<<(long double)(f[i/2])<<endl;
		file<<setprecision(10)<<i/2<<"  "<<setprecision(10)<<(double)log(i/2)<<"  "<<setprecision(10)<<(double)log((double)(f[i/2]))<<"  "<<setprecision(10)<<(long double)(f[i/2])<<endl;
	}

}


int main(int argc, char* argv[]) {
	N=atoi(argv[1]);
	E =atoi(argv[2]);
	filenum=atoi(argv[3]);

	firstreturn="1streturn_N"+to_string(N)+"_en"+to_string(E)+"_fnum"+to_string(filenum)+".dat";

	first_return();
	return 0;
}
