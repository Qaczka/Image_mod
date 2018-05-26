#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE * fp;
	FILE * nowy;

	fp = fopen("i100.ppm", "r");
	nowy = fopen("zmieniony.ppm", "w");

	char naglowek[3];
	int m, n, prog, szerokosc, wysokosc;
	prog = 0;

	for (m = 0; m<3; m++)
	{
		fscanf(fp, "%c", &naglowek[m]);
		printf("%c", naglowek[m]);
		fprintf(nowy, "%c", naglowek[m]);
	}

	for (m = 0; m<3; m++)
	{

		if (m == 2)
		{
			fprintf(nowy, "\n");
			printf("\n");
		}
		fscanf(fp, "%i ", &n);
		printf("%i ", n);
		fprintf(nowy, "%i ", n);
		if (m == 0)
		{
			szerokosc = n;
		}
		if (m == 1)
		{
			wysokosc = n;
		}
	}

	fprintf(nowy, "\n");
	printf("\n");

	//--------------------------------------------------------------------------------------------------------------------\\

	fpos_t pos;
	fgetpos(fp, &pos);

	printf("Aktualna pozycja w pliku: %ld\n", pos);

	//--------------------------------------------------------------------------------------------------------------------\\

	int r, g, b, s;
	int zmienna;
	s = 0;

	printf("Ktory program chcesz wlaczyc? 1, 2, 3 czy 4?\n");
	scanf("%i", &prog);
	if (prog == 1)
	{
		printf("Który kolor chcesz odwrócic? R(1), G(2) czy B(3)?");
		scanf("%i", &zmienna);

		while (!feof(fp))
		{
			fscanf(fp, "%i", &r);
			fscanf(fp, "%i", &g);
			fscanf(fp, "%i", &b);


			if (zmienna == 1)
				r = 255 - r;
			if (zmienna == 2)
				g = 255 - g;
			if (zmienna == 3)
				b = 255 - b;

			s++;


			//printf("%i ", r);
			//printf("%i ", g);
			//printf("%i ", b);

			fprintf(nowy, "%i ", r);
			fprintf(nowy, "%i ", g);
			fprintf(nowy, "%i ", b);

			if (s == naglowek[0])
			{
				fprintf(nowy, "\n");
				printf("\n");
				s = 0;
			}
		}
	}

	//--------------------------------------------------------------------------------------------------------------------\\

	int srednia;

	if (prog == 2)
	{
		while (!feof(fp))
		{
			fscanf(fp, "%i", &r);
			fscanf(fp, "%i", &g);
			fscanf(fp, "%i", &b);


			srednia = (r + g + b) / 3;
			r = srednia;
			g = srednia;
			b = srednia;



			s++;


			//printf("%i ", r);
			//printf("%i ", g);
			//printf("%i ", b);

			fprintf(nowy, "%i ", r);
			fprintf(nowy, "%i ", g);
			fprintf(nowy, "%i ", b);

			if (s == naglowek[0])
			{
				fprintf(nowy, "\n");
				printf("\n");
				s = 0;
			}
		}
	}

	//--------------------------------------------------------------------------------------------------------------------\\

	if (prog == 3)
	{
		scanf("%i", &zmienna);
		while (!feof(fp))
		{
			fscanf(fp, "%i", &r);
			fscanf(fp, "%i", &g);
			fscanf(fp, "%i", &b);


			if (zmienna == 1)
				r = 0;
			if (zmienna == 2)
				g = 0;
			if (zmienna == 3)
				b = 0;

			s++;


			//printf("%i ", r);
			//printf("%i ", g);
			//printf("%i ", b);

			fprintf(nowy, "%i ", r);
			fprintf(nowy, "%i ", g);
			fprintf(nowy, "%i ", b);

			if (s == naglowek[0])
			{
				fprintf(nowy, "\n");
				printf("\n");
				s = 0;
			}
		}
	}

	//--------------------------------------------------------------------------------------------------------------------\\

	int l, c, p, v, q;

	p = 0;
	v = 0;

	if (prog == 4)
	{


		for (q = 0; q<szerokosc; q++)// ILOSC KOLUMN
		{
			//printf("Q to: %i%%\n",((q/szerokosc)*100));

			for (l = 500; l>q; l--)
			{
				fscanf(fp, "%i", &r);
				fscanf(fp, "%i", &g);
				fscanf(fp, "%i", &b);
			}

			s++;

			//printf("%i ", r);
			//printf("%i ", g);
			//printf("%i ", b);

			fprintf(nowy, "%i ", r);
			fprintf(nowy, "%i ", g);
			fprintf(nowy, "%i ", b);

			if (s == szerokosc)
			{
				fprintf(nowy, "\n");
				printf("\n");
				s = 0;
			}


			for (c = 1; c<wysokosc; c++)// RAZY WIERSZE ( RAZY ILE
			{


				for (l = 0; l<szerokosc; l++)//PRZESUNIECIE(MAX)
				{
					fscanf(fp, "%i", &r);
					fscanf(fp, "%i", &g);
					fscanf(fp, "%i", &b);
				}

				//printf("%i ", szerokosc);
				//printf("%i ", wysokosc);


				s++;

				//printf("%i ", r);
				//printf("%i ", g);
				//printf("%i ", b);

				fprintf(nowy, "%i ", r);
				fprintf(nowy, "%i ", g);
				fprintf(nowy, "%i ", b);

				if (s == szerokosc)
				{
					fprintf(nowy, "\n");
					printf("\n");
					s = 0;
				}
				v++;

			}
			fsetpos(fp, &pos);
		}
	}


	fclose(fp);
	fclose(nowy);


	return 0;
}
