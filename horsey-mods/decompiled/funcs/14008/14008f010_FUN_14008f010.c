// Address: 0x14008f010
// Ghidra name: FUN_14008f010
// ============ 0x14008f010 FUN_14008f010 (size=268) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



ulonglong FUN_14008f010(longlong param_1)



{

  int iVar1;

  undefined8 uVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  ulonglong in_RAX;

  undefined8 in_stack_ffffffffffffffc8;

  undefined4 uVar6;

  char *local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  ulonglong uStack_10;

  

  uVar6 = (undefined4)((ulonglong)in_stack_ffffffffffffffc8 >> 0x20);

  if (*(int *)(param_1 + 0x268) != 0) {

    return in_RAX & 0xffffffffffffff00;

  }

  local_28 = (char *)0x0;

  uStack_20 = 0;

  local_18 = 0;

  uStack_10 = 0;

  local_28 = (char *)FUN_1400285e0(0x40);

  uVar2 = s_I_sold_all_my_rides__might_as_we_14030b970._8_8_;

  local_18 = _DAT_1403041b0;

  uStack_10 = _UNK_1403041b8;

  *(undefined8 *)local_28 = s_I_sold_all_my_rides__might_as_we_14030b970._0_8_;

  *(undefined8 *)(local_28 + 8) = uVar2;

  uVar5 = s_I_sold_all_my_rides__might_as_we_14030b970._28_4_;

  uVar4 = s_I_sold_all_my_rides__might_as_we_14030b970._24_4_;

  uVar3 = s_I_sold_all_my_rides__might_as_we_14030b970._20_4_;

  *(undefined4 *)(local_28 + 0x10) = s_I_sold_all_my_rides__might_as_we_14030b970._16_4_;

  *(undefined4 *)(local_28 + 0x14) = uVar3;

  *(undefined4 *)(local_28 + 0x18) = uVar4;

  *(undefined4 *)(local_28 + 0x1c) = uVar5;

  uVar2 = s_I_sold_all_my_rides__might_as_we_14030b970._40_8_;

  *(undefined8 *)(local_28 + 0x20) = s_I_sold_all_my_rides__might_as_we_14030b970._32_8_;

  *(undefined8 *)(local_28 + 0x28) = uVar2;

  local_28[0x30] = '\0';

  FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_28,0,CONCAT44(uVar6,DAT_140303758));

  if (0xf < uStack_10) {

    if (0xfff < uStack_10 + 1) {

      if ((char *)0x1f < local_28 + (-8 - *(longlong *)(local_28 + -8))) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    FUN_1402c7088();

  }

  iVar1 = *(int *)(*(longlong *)(param_1 + 0x148) + 0x208);

  if (iVar1 < 2) {

    iVar1 = 2;

  }

  *(int *)(*(longlong *)(param_1 + 0x148) + 0x208) = iVar1;

  return CONCAT71((uint7)(uint3)((uint)iVar1 >> 8),1);

}




