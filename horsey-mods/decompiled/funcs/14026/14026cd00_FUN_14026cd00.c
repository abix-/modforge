// Address: 0x14026cd00
// Ghidra name: FUN_14026cd00
// ============ 0x14026cd00 FUN_14026cd00 (size=230) ============


void FUN_14026cd00(longlong *param_1)



{

  longlong *plVar1;

  undefined4 uVar2;

  

  if ((*(char *)((longlong)param_1 + 0x35) == '\0') &&

     (*(undefined1 *)((longlong)param_1 + 0x35) = 1, uVar2 = DAT_140304c38,

     (char)param_1[0x13] != '\0')) {

    plVar1 = param_1 + 4;

    if ((*(longlong *)(*param_1 + 0xa0) == 0) || ((int)*plVar1 == 2)) {

      FUN_14015a190(param_1[1],2,DAT_140304c38);

      FUN_14015a190(param_1[1],1,uVar2);

    }

    if ((*(longlong *)(*param_1 + 0xa0) != 0) && ((int)*plVar1 == 1)) {

      FUN_14015a190(param_1[1],4,uVar2);

      FUN_14015a190(param_1[1],3,uVar2);

    }

    if ((*(longlong *)(*param_1 + 0xa0) != 0) && ((int)*plVar1 == 2)) {

      FUN_14015a190(param_1[1],6,uVar2);

      FUN_14015a190(param_1[1],5,uVar2);

    }

  }

  return;

}




