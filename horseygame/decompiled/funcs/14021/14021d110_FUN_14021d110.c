// Address: 0x14021d110
// Ghidra name: FUN_14021d110
// ============ 0x14021d110 FUN_14021d110 (size=261) ============


undefined8 FUN_14021d110(char *param_1,undefined4 *param_2)



{

  BOOL BVar1;

  size_t sVar2;

  LPCWSTR lpFileName;

  undefined8 uVar3;

  uint local_38;

  undefined4 local_34;

  undefined4 local_30;

  undefined4 local_2c;

  undefined4 local_28;

  undefined4 local_24;

  undefined4 local_20;

  undefined4 local_1c;

  undefined4 local_18;

  

  sVar2 = strlen(param_1);

  lpFileName = (LPCWSTR)FUN_140197820("UTF-16LE",&DAT_14039c6f0,param_1,sVar2 + 1);

  if (lpFileName == (LPCWSTR)0x0) {

    return 0;

  }

  BVar1 = GetFileAttributesExW(lpFileName,GetFileExInfoStandard,&local_38);

  FUN_1401841e0();

  if (BVar1 == 0) {

    uVar3 = FUN_1401a9ed0("Can\'t stat");

    return uVar3;

  }

  if ((local_38 & 0x10) == 0) {

    if ((local_38 & 0x1040) == 0) {

      *param_2 = 1;

    }

    else {

      *param_2 = 3;

    }

    uVar3 = CONCAT44(local_1c,local_18);

  }

  else {

    *param_2 = 2;

    uVar3 = 0;

  }

  *(undefined8 *)(param_2 + 2) = uVar3;

  uVar3 = FUN_14017d450(local_34,local_30);

  *(undefined8 *)(param_2 + 4) = uVar3;

  uVar3 = FUN_14017d450(local_24,local_20);

  *(undefined8 *)(param_2 + 6) = uVar3;

  uVar3 = FUN_14017d450(local_2c,local_28);

  *(undefined8 *)(param_2 + 8) = uVar3;

  return 1;

}




