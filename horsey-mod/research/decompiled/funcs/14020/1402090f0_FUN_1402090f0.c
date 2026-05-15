// Address: 0x1402090f0
// Ghidra name: FUN_1402090f0
// ============ 0x1402090f0 FUN_1402090f0 (size=217) ============


undefined4 FUN_1402090f0(short param_1,short param_2,undefined8 param_3,char *param_4)



{

  longlong lVar1;

  longlong lVar2;

  int iVar3;

  

  DAT_1403e4ec8 = 1;

  lVar1 = DAT_1403ffc50;

  while( true ) {

    if (lVar1 == 0) {

      return 0;

    }

    if (((param_1 == *(short *)(lVar1 + 0x18)) &&

        ((param_2 == *(short *)(lVar1 + 0x1a) ||

         ((param_2 == 0 &&

          (((param_4 != (char *)0x0 &&

            (lVar2 = thunk_FUN_1402c9340(*(undefined8 *)(lVar1 + 8),param_4), lVar2 != 0)) ||

           ((*(short *)(lVar1 + 0x18) == 0x45e && (*(short *)(lVar1 + 0x1a) == 0x2a1)))))))))) ||

       ((((param_4 != (char *)0x0 &&

          (iVar3 = strcmp(param_4,"Xbox One Game Controller"), iVar3 == 0)) &&

         (*(short *)(lVar1 + 0x18) == 0x45e)) && (*(short *)(lVar1 + 0x1a) == 0x2ff)))) break;

    lVar1 = *(longlong *)(lVar1 + 0x58);

  }

  return 1;

}




