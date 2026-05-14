// Address: 0x14017b6f0
// Ghidra name: FUN_14017b6f0
// ============ 0x14017b6f0 FUN_14017b6f0 (size=466) ============


void FUN_14017b6f0(uint param_1,uint *param_2,uint *param_3,undefined1 *param_4,undefined1 *param_5,

                  undefined1 *param_6)



{

  longlong lVar1;

  uint uVar2;

  uint uVar3;

  undefined1 *puVar4;

  undefined1 *puVar5;

  undefined1 *puVar6;

  undefined1 local_res10 [8];

  

  puVar5 = local_res10;

  if (param_4 != (undefined1 *)0x0) {

    puVar5 = param_4;

  }

  puVar6 = local_res10;

  if (param_5 != (undefined1 *)0x0) {

    puVar6 = param_5;

  }

  puVar4 = local_res10;

  if (param_6 != (undefined1 *)0x0) {

    puVar4 = param_6;

  }

  if (param_2 == (uint *)0x0) goto LAB_14017b8a8;

  uVar2 = *param_2;

  if (uVar2 == 0) {

LAB_14017b7bf:

    uVar3 = (int)uVar2 >> 0x18 & 0xf;

    if ((uVar3 != 0xc) && (1 < uVar3 - 2)) {

      if (((uVar2 == 0) || ((uVar2 & 0xf0000000) == 0x10000000)) &&

         ((((byte)(uVar2 >> 0x18) & 0xf) == 6 && ((uVar2 & 0xf0000) == 0x70000)))) {

        *puVar5 = (char)(((param_2[2] & param_1) >> ((byte)param_2[7] & 0x1f)) >> 2);

        *puVar6 = (char)(((param_2[3] & param_1) >> (*(byte *)((longlong)param_2 + 0x1d) & 0x1f)) >>

                        2);

        *puVar4 = (char)(((param_2[4] & param_1) >> (*(byte *)((longlong)param_2 + 0x1e) & 0x1f)) >>

                        2);

        return;

      }

LAB_14017b836:

      *puVar5 = (&PTR_DAT_1403e28a0)[(byte)param_2[6]]

                [(param_2[2] & param_1) >> ((byte)param_2[7] & 0x3f)];

      *puVar6 = (&PTR_DAT_1403e28a0)[*(byte *)((longlong)param_2 + 0x19)]

                [(param_2[3] & param_1) >> (*(byte *)((longlong)param_2 + 0x1d) & 0x3f)];

      *puVar4 = (&PTR_DAT_1403e28a0)[*(byte *)((longlong)param_2 + 0x1a)]

                [(param_2[4] & param_1) >> (*(byte *)((longlong)param_2 + 0x1e) & 0x3f)];

      return;

    }

  }

  else {

    if ((uVar2 & 0xf0000000) != 0x10000000) goto LAB_14017b836;

    if (((int)uVar2 >> 0x18 & 0xfU) != 1) goto LAB_14017b7bf;

  }

  if ((param_3 != (uint *)0x0) && (param_1 < *param_3)) {

    lVar1 = (ulonglong)param_1 * 4;

    *puVar5 = *(undefined1 *)(lVar1 + *(longlong *)(param_3 + 2));

    *puVar6 = *(undefined1 *)(lVar1 + 1 + *(longlong *)(param_3 + 2));

    *puVar4 = *(undefined1 *)(lVar1 + 2 + *(longlong *)(param_3 + 2));

    return;

  }

LAB_14017b8a8:

  *puVar4 = 0;

  *puVar6 = 0;

  *puVar5 = 0;

  return;

}




