void  multi(float *real1, float *compx1, float *real2, float *compx2, float *real3, float *compx3)
	{
	*real3=*real1 * *real2 - *compx1 * *compx2;
	*compx3=*compx1 * *real2 + *compx2 * *real1;
	}