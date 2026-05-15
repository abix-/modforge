// Address: 0x14017bb00
// Ghidra name: FUN_14017bb00
// ============ 0x14017bb00 FUN_14017bb00 (size=151) ============


ulonglong FUN_14017bb00(undefined8 param_1,uint param_2,longlong param_3)



{

  char cVar1;

  byte bVar2;

  ulonglong in_RAX;

  byte local_res18 [8];

  

  if (param_3 == 0) {

    return in_RAX & 0xffffffffffffff00;

  }

  cVar1 = FUN_1401aaff0(param_1,param_2,local_res18);

  if (cVar1 == '\0') {

    bVar2 = FUN_14017a230(param_3,param_2 >> 0x18,param_2 >> 0x10,param_2 >> 8,(char)param_2);

    FUN_1401ab100(param_1,param_2,bVar2,1);

    local_res18[0] = bVar2;

  }

  return (ulonglong)local_res18[0];

}




