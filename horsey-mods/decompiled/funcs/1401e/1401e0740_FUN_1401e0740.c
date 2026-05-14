// Address: 0x1401e0740
// Ghidra name: FUN_1401e0740
// ============ 0x1401e0740 FUN_1401e0740 (size=250) ============


undefined1 FUN_1401e0740(longlong param_1,int *param_2,int param_3,int *param_4,undefined8 *param_5)



{

  longlong lVar1;

  undefined1 uVar2;

  char cVar3;

  

  lVar1 = *(longlong *)(param_2 + 0x4e);

  if (lVar1 == 0) {

    uVar2 = FUN_14012e850("Texture is not currently available");

    return uVar2;

  }

  if (*param_2 == 0x13000801) {

    *param_4 = (param_3 == 1) + 1;

  }

  else if (*(char *)(lVar1 + 0x48) != '\0') {

    *param_4 = 3;

  }

  *param_5 = *(undefined8 *)(lVar1 + 0x30);

  cVar3 = FUN_1401dcd50(*(undefined8 *)(param_1 + 0x10),lVar1,0);

  if ((cVar3 != '\0') &&

     ((*(longlong *)(param_2 + 0x38) == 0 ||

      (cVar3 = FUN_1401dcd50(*(undefined8 *)(param_1 + 0x10),

                             *(undefined8 *)(*(longlong *)(param_2 + 0x38) + 0x10),1), cVar3 != '\0'

      )))) {

    if (*(char *)(lVar1 + 0x48) == '\0') {

      return true;

    }

    cVar3 = FUN_1401dcd50(*(undefined8 *)(param_1 + 0x10),lVar1 + 0x50,1);

    if (cVar3 != '\0') {

      cVar3 = FUN_1401dcd50(*(undefined8 *)(param_1 + 0x10),lVar1 + 0x78,2);

      return cVar3 != '\0';

    }

  }

  return false;

}




