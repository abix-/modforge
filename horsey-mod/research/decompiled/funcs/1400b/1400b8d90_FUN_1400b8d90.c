// Address: 0x1400b8d90
// Ghidra name: FUN_1400b8d90
// ============ 0x1400b8d90 FUN_1400b8d90 (size=498) ============


void FUN_1400b8d90(longlong param_1)



{

  undefined8 uVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  undefined4 uVar6;

  int iVar7;

  longlong lVar8;

  float fVar9;

  undefined4 uVar10;

  undefined4 local_res10;

  undefined4 local_res14;

  undefined4 local_res18;

  float fStackX_1c;

  ulonglong in_stack_ffffffffffffff38;

  longlong local_98;

  longlong local_90;

  longlong local_88;

  

  FUN_1400b5b50(param_1,&local_98);

  if (local_98 != local_90) {

    iVar7 = FUN_1400c6580(local_90 - local_98 >> 3 & 0xffffffff);

    uVar6 = DAT_14039ca38;

    uVar5 = DAT_14030d9ec;

    uVar4 = DAT_14030d9dc;

    uVar3 = DAT_14030d938;

    uVar2 = DAT_140304c5c;

    uVar1 = *(undefined8 *)(local_98 + (longlong)iVar7 * 8);

    _local_res18 = CONCAT44((float)((ulonglong)uVar1 >> 0x20) + DAT_140304c54,(int)uVar1);

    fVar9 = (float)(*(uint *)(param_1 + 0x25c) ^ DAT_14039cac0);

    lVar8 = 4;

    if (*(float *)(param_1 + 0x260) <= fVar9 && fVar9 != *(float *)(param_1 + 0x260)) {

      lVar8 = 7;

    }

    do {

      uVar10 = FUN_1400c6940(uVar5,uVar4);

      local_res10 = FUN_1400c6940(uVar2,uVar6);

      in_stack_ffffffffffffff38 = in_stack_ffffffffffffff38 & 0xffffffff00000000;

      local_res14 = uVar10;

      FUN_1400c8dc0(*(undefined8 *)(param_1 + 0x1f0),0xffffffff,&local_res18,&local_res10,

                    in_stack_ffffffffffffff38,0,&DAT_1403da464,0x1e,uVar3);

      lVar8 = lVar8 + -1;

    } while (lVar8 != 0);

  }

  if (local_98 != 0) {

    if ((0xfff < (local_88 - local_98 & 0xfffffffffffffff8U)) &&

       (0x1f < (local_98 - *(longlong *)(local_98 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

  }

  return;

}




