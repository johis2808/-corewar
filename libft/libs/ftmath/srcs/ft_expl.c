/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:26:10 by abaurens          #+#    #+#             */
/*   Updated: 2019/12/03 08:15:19 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <float.h>
#include <sys/cdefs.h>
#include "ftmath/ft_expl.h"
#include "ftmath/fpmath.h"

static const t_tab	g_tbl[128] = {
	{0x1p+0, 0x0p+0},
	{0x1.0163da9fb3335p+0, 0x1.b61299ab8cdb7p-54},
	{0x1.02c9a3e778060p+0, 0x1.dcdef95949ef4p-53},
	{0x1.04315e86e7f84p+0, 0x1.7ae71f3441b49p-53},
	{0x1.059b0d3158574p+0, 0x1.d73e2a475b465p-55},
	{0x1.0706b29ddf6ddp+0, 0x1.8db880753b0f6p-53},
	{0x1.0874518759bc8p+0, 0x1.186be4bb284ffp-57},
	{0x1.09e3ecac6f383p+0, 0x1.1487818316136p-54},
	{0x1.0b5586cf9890fp+0, 0x1.8a62e4adc610bp-54},
	{0x1.0cc922b7247f7p+0, 0x1.01edc16e24f71p-54},
	{0x1.0e3ec32d3d1a2p+0, 0x1.03a1727c57b53p-59},
	{0x1.0fb66affed31ap+0, 0x1.e464123bb1428p-53},
	{0x1.11301d0125b50p+0, 0x1.49d77e35db263p-53},
	{0x1.12abdc06c31cbp+0, 0x1.f72575a649ad2p-53},
	{0x1.1429aaea92ddfp+0, 0x1.66820328764b1p-53},
	{0x1.15a98c8a58e51p+0, 0x1.2406ab9eeab0ap-55},
	{0x1.172b83c7d517ap+0, 0x1.b9bef918a1d63p-53},
	{0x1.18af9388c8de9p+0, 0x1.777ee1734784ap-53},
	{0x1.1a35beb6fcb75p+0, 0x1.e5b4c7b4968e4p-55},
	{0x1.1bbe084045cd3p+0, 0x1.3563ce56884fcp-53},
	{0x1.1d4873168b9aap+0, 0x1.e016e00a2643cp-54},
	{0x1.1ed5022fcd91cp+0, 0x1.71033fec2243ap-53},
	{0x1.2063b88628cd6p+0, 0x1.dc775814a8495p-55},
	{0x1.21f49917ddc96p+0, 0x1.2a97e9494a5eep-55},
	{0x1.2387a6e756238p+0, 0x1.9b07eb6c70573p-54},
	{0x1.251ce4fb2a63fp+0, 0x1.ac155bef4f4a4p-55},
	{0x1.26b4565e27cddp+0, 0x1.2bd339940e9d9p-55},
	{0x1.284dfe1f56380p+0, 0x1.2d9e2b9e07941p-53},
	{0x1.29e9df51fdee1p+0, 0x1.612e8afad1255p-55},
	{0x1.2b87fd0dad98fp+0, 0x1.fbbd48ca71f95p-53},
	{0x1.2d285a6e4030bp+0, 0x1.0024754db41d5p-54},
	{0x1.2ecafa93e2f56p+0, 0x1.1ca0f45d52383p-56},
	{0x1.306fe0a31b715p+0, 0x1.6f46ad23182e4p-55},
	{0x1.32170fc4cd831p+0, 0x1.a9ce78e18047cp-55},
	{0x1.33c08b26416ffp+0, 0x1.32721843659a6p-54},
	{0x1.356c55f929ff0p+0, 0x1.928c468ec6e76p-53},
	{0x1.371a7373aa9cap+0, 0x1.4e28aa05e8a8fp-53},
	{0x1.38cae6d05d865p+0, 0x1.0b53961b37da2p-53},
	{0x1.3a7db34e59ff6p+0, 0x1.d43792533c144p-53},
	{0x1.3c32dc313a8e4p+0, 0x1.08003e4516b1ep-53},
	{0x1.3dea64c123422p+0, 0x1.ada0911f09ebcp-55},
	{0x1.3fa4504ac801bp+0, 0x1.417ee03548306p-53},
	{0x1.4160a21f72e29p+0, 0x1.f0864b71e7b6cp-53},
	{0x1.431f5d950a896p+0, 0x1.b8e088728219ap-53},
	{0x1.44e086061892dp+0, 0x1.89b7a04ef80d0p-59},
	{0x1.46a41ed1d0057p+0, 0x1.c944bd1648a76p-54},
	{0x1.486a2b5c13cd0p+0, 0x1.3c1a3b69062f0p-56},
	{0x1.4a32af0d7d3dep+0, 0x1.9cb62f3d1be56p-54},
	{0x1.4bfdad5362a27p+0, 0x1.d4397afec42e2p-56},
	{0x1.4dcb299fddd0dp+0, 0x1.8ecdbbc6a7833p-54},
	{0x1.4f9b2769d2ca6p+0, 0x1.5a67b16d3540ep-53},
	{0x1.516daa2cf6641p+0, 0x1.8225ea5909b04p-53},
	{0x1.5342b569d4f81p+0, 0x1.be1507893b0d5p-53},
	{0x1.551a4ca5d920ep+0, 0x1.8a5d8c4048699p-53},
	{0x1.56f4736b527dap+0, 0x1.9bb2c011d93adp-54},
	{0x1.58d12d497c7fdp+0, 0x1.295e15b9a1de8p-55},
	{0x1.5ab07dd485429p+0, 0x1.6324c054647adp-54},
	{0x1.5c9268a5946b7p+0, 0x1.c4b1b816986a2p-60},
	{0x1.5e76f15ad2148p+0, 0x1.ba6f93080e65ep-54},
	{0x1.605e1b976dc08p+0, 0x1.60edeb25490dcp-53},
	{0x1.6247eb03a5584p+0, 0x1.63e1f40dfa5b5p-53},
	{0x1.6434634ccc31fp+0, 0x1.8edf0e2989db3p-53},
	{0x1.6623882552224p+0, 0x1.224fb3c5371e6p-53},
	{0x1.68155d44ca973p+0, 0x1.038ae44f73e65p-57},
	{0x1.6a09e667f3bccp+0, 0x1.21165f626cdd5p-53},
	{0x1.6c012750bdabep+0, 0x1.daed533001e9ep-53},
	{0x1.6dfb23c651a2ep+0, 0x1.e441c597c3775p-53},
	{0x1.6ff7df9519483p+0, 0x1.9f0fc369e7c42p-53},
	{0x1.71f75e8ec5f73p+0, 0x1.ba46e1e5de15ap-53},
	{0x1.73f9a48a58173p+0, 0x1.7ab9349cd1562p-53},
	{0x1.75feb564267c8p+0, 0x1.7edd354674916p-53},
	{0x1.780694fde5d3fp+0, 0x1.866b80a02162dp-54},
	{0x1.7a11473eb0186p+0, 0x1.afaa2047ed9b4p-53},
	{0x1.7c1ed0130c132p+0, 0x1.f124cd1164dd6p-54},
	{0x1.7e2f336cf4e62p+0, 0x1.05d02ba15797ep-56},
	{0x1.80427543e1a11p+0, 0x1.6c1bccec9346bp-53},
	{0x1.82589994cce12p+0, 0x1.159f115f56694p-53},
	{0x1.8471a4623c7acp+0, 0x1.9ca5ed72f8c81p-53},
	{0x1.868d99b4492ecp+0, 0x1.01c83b21584a3p-53},
	{0x1.88ac7d98a6699p+0, 0x1.994c2f37cb53ap-54},
	{0x1.8ace5422aa0dbp+0, 0x1.6e9f156864b27p-54},
	{0x1.8cf3216b5448bp+0, 0x1.de55439a2c38bp-53},
	{0x1.8f1ae99157736p+0, 0x1.5cc13a2e3976cp-55},
	{0x1.9145b0b91ffc5p+0, 0x1.114c368d3ed6ep-53},
	{0x1.93737b0cdc5e4p+0, 0x1.e8a0387e4a814p-53},
	{0x1.95a44cbc8520ep+0, 0x1.d36906d2b41f9p-53},
	{0x1.97d829fde4e4fp+0, 0x1.173d241f23d18p-53},
	{0x1.9a0f170ca07b9p+0, 0x1.7462137188ce7p-53},
	{0x1.9c49182a3f090p+0, 0x1.c7c46b071f2bep-56},
	{0x1.9e86319e32323p+0, 0x1.824ca78e64c6ep-56},
	{0x1.a0c667b5de564p+0, 0x1.6535b51719567p-53},
	{0x1.a309bec4a2d33p+0, 0x1.6305c7ddc36abp-54},
	{0x1.a5503b23e255cp+0, 0x1.1684892395f0fp-53},
	{0x1.a799e1330b358p+0, 0x1.bcb7ecac563c7p-54},
	{0x1.a9e6b5579fdbfp+0, 0x1.0fac90ef7fd31p-54},
	{0x1.ac36bbfd3f379p+0, 0x1.81b72cd4624ccp-53},
	{0x1.ae89f995ad3adp+0, 0x1.7a1cd345dcc81p-54},
	{0x1.b0e07298db665p+0, 0x1.2108559bf8deep-53},
	{0x1.b33a2b84f15fap+0, 0x1.ed7fa1cf7b290p-53},
	{0x1.b59728de55939p+0, 0x1.1c7102222c90ep-53},
	{0x1.b7f76f2fb5e46p+0, 0x1.d54f610356a79p-53},
	{0x1.ba5b030a10649p+0, 0x1.0819678d5eb69p-53},
	{0x1.bcc1e904bc1d2p+0, 0x1.23dd07a2d9e84p-55},
	{0x1.bf2c25bd71e08p+0, 0x1.0811ae04a31c7p-53},
	{0x1.c199bdd85529cp+0, 0x1.11065895048ddp-55},
	{0x1.c40ab5fffd07ap+0, 0x1.b4537e083c60ap-54},
	{0x1.c67f12e57d14bp+0, 0x1.2884dff483cadp-54},
	{0x1.c8f6d9406e7b5p+0, 0x1.1acbc48805c44p-56},
	{0x1.cb720dcef9069p+0, 0x1.503cbd1e949dbp-56},
	{0x1.cdf0b555dc3f9p+0, 0x1.889f12b1f58a3p-53},
	{0x1.d072d4a07897bp+0, 0x1.1a1e45e4342b2p-53},
	{0x1.d2f87080d89f1p+0, 0x1.15bc247313d44p-53},
	{0x1.d5818dcfba487p+0, 0x1.2ed02d75b3707p-55},
	{0x1.d80e316c98397p+0, 0x1.7709f3a09100cp-53},
	{0x1.da9e603db3285p+0, 0x1.c2300696db532p-54},
	{0x1.dd321f301b460p+0, 0x1.2da5778f018c3p-54},
	{0x1.dfc97337b9b5ep+0, 0x1.72d195873da52p-53},
	{0x1.e264614f5a128p+0, 0x1.424ec3f42f5b5p-53},
	{0x1.e502ee78b3ff6p+0, 0x1.39e8980a9cc8fp-55},
	{0x1.e7a51fbc74c83p+0, 0x1.2d522ca0c8de2p-54},
	{0x1.ea4afa2a490d9p+0, 0x1.0b1ee7431ebb6p-53},
	{0x1.ecf482d8e67f0p+0, 0x1.1b60625f7293ap-53},
	{0x1.efa1bee615a27p+0, 0x1.dc7f486a4b6b0p-54},
	{0x1.f252b376bba97p+0, 0x1.3a1a5bf0d8e43p-54},
	{0x1.f50765b6e4540p+0, 0x1.9d3e12dd8a18bp-54},
	{0x1.f7bfdad9cbe13p+0, 0x1.1227697fce57bp-53},
	{0x1.fa7c1819e90d8p+0, 0x1.74853f3a5931ep-55},
	{0x1.fd3c22b8f71f1p+0, 0x1.2eb74966579e7p-57}
};

static void			k_ft_expl(long double x, long double *hp, long double *lp,
									int *kp)
{
	long double	fn;
	long double	r;
	long double	q;
	long double	z;
	int			n;

	fn = (x * INV_L) + 0x1.8p64 / 2 - 0x1.8p64 / 2;
	r = x - fn * L1 - fn * L2;
	*kp = ((int)fn) >> LOG2_INTERVALS;
	n = ((unsigned)fn) % 128;
	*hp = g_tbl[n].hi;
	z = r * r;
	q = (fn * -L2) + z * A2 + z * r * (A3 + r * A4 + z * (A5 + r * A6));
	r = (long double)g_tbl[n].lo + g_tbl[n].hi;
	*lp = g_tbl[n].lo + r * (q + (x - fn * L1));
}

static long double	compute_expl(long double x)
{
	long double		twopk;
	long double		hi;
	long double		lo;
	int				k;

	twopk = 1;
	k_ft_expl(x, &hi, &lo, &k);
	hi += lo;
	if (k >= LDBL_MIN_EXP)
	{
		if (k == LDBL_MAX_EXP)
			return (hi * 2 * 0x1p16383L);
		set_ldbl_expsign(&twopk, (LDBL_MAX_EXP - 1) + k);
		return (hi * twopk);
	}
	set_ldbl_expsign(&twopk, (LDBL_MAX_EXP - 1) + k + 10000);
	return (hi * twopk * 0x1p-10000L);
}

long double			ft_expl(long double x)
{
	t_ieeel2bits	u;
	uint16_t		hx;
	uint16_t		ix;

	u.e = x;
	hx = u.xbits.expsign;
	ix = hx & 0x7fff;
	if (ix >= (LDBL_MAX_EXP - 1) + 13)
	{
		if (ix == (LDBL_MAX_EXP - 1) + LDBL_MAX_EXP)
		{
			if (hx & 0x8000)
				return (-1 / x);
			return (x + x);
		}
		if (x > ld80c(0xb17217f7d1cf79ab, 13, 11356.5234062941439488L).e)
			return (0x1p10000L * 0x1p10000L);
		if (x < ld80c(0xb21dfe7f09e2baa9, 13, -11399.4985314888605581L).e)
			return (0x1p-10000L * 0x1p-10000L);
	}
	else if (ix < (LDBL_MAX_EXP - 1) - 75)
		return (1 + x);
	return (compute_expl(x));
}
