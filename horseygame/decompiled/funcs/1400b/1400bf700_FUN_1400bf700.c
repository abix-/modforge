// Address: 0x1400bf700
// Ghidra name: FUN_1400bf700
// ============ 0x1400bf700 FUN_1400bf700 (size=195) ============


void FUN_1400bf700(longlong *param_1)



{

  undefined8 *puVar1;

  longlong lVar2;

  undefined8 *puVar3;

  longlong lVar4;

  

  puVar3 = (undefined8 *)*param_1;

  if (puVar3 != (undefined8 *)0x0) {

    puVar1 = (undefined8 *)param_1[1];

    for (; puVar3 != puVar1; puVar3 = puVar3 + 0x2d) {

      puVar3[0x14] = b2Shape::vftable;

      *puVar3 = b2Shape::vftable;

    }

    lVar2 = *param_1;

    lVar4 = lVar2;

    if ((0xfff < (ulonglong)(((param_1[2] - lVar2) / 0x168) * 0x168)) &&

       (lVar4 = *(longlong *)(lVar2 + -8), 0x1f < (lVar2 - lVar4) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(lVar4);

    *param_1 = 0;

    param_1[1] = 0;

    param_1[2] = 0;

  }

  return;

}




