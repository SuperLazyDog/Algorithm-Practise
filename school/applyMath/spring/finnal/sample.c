if (y.inf > 0.) {
	if (x.inf >= 0.) {
		fesetround(FE_DOWNWARD);
		z.inf = x.inf / y.sup;
		fesetround(FE_UPWARD);
		z.sup = x.sup /  y.inf;
	} else if (x.sup <= 0.) {
		fesetround(FE_DOWNWARD);
		z.inf = x.inf / y.inf;
		fesetround(FE_UPWARD);
		z.sup = x.sup / y.sup;
	} else {
		fesetround(FE_DOWNWARD);
		z.inf = x.inf / y.inf;
		fesetround(FE_UPWARD);
		z.sup = x.sup / y.inf;
	}
} else if (y.sup < 0.) {
	if (x.inf >= 0.) {
		fesetround(FE_DOWNWARD);
		z.inf = x.sup / y.sup;
		fesetround(FE_UPWARD);
		z.sup = x.inf / y.inf;
	} else if (x.sup <= 0.) {
		fesetround(FE_DOWNWARD);
		z.inf = x.sup / y.inf;
		fesetround(FE_UPWARD);
		z.sup = x.inf / y.sup;
	} else {
		fesetround(FE_DOWNWARD);
		z.inf = x.sup / y.sup;
		fesetround(FE_UPWARD);
		z.sup = x.inf / y.sup;
	}
}
