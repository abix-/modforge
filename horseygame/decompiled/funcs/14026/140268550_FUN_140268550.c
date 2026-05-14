// Address: 0x140268550
// Ghidra name: FUN_140268550
// ============ 0x140268550 FUN_140268550 (size=289) ============


ulonglong FUN_140268550(undefined8 param_1,char *param_2,int param_3,short param_4,short param_5,

                       undefined2 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,

                       undefined4 param_10)



{

  int iVar1;

  undefined4 extraout_var;

  ulonglong uVar2;

  

  iVar1 = strcmp(param_2,"HORI Wireless Switch Pad");

  uVar2 = CONCAT44(extraout_var,iVar1);

  if ((((iVar1 != 0) &&

       (uVar2 = FUN_140268370(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,

                              param_9,param_10), (char)uVar2 == '\0')) &&

      (uVar2 = FUN_140268470(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9

                             ,param_10), (char)uVar2 == '\0')) &&

     ((param_3 == 7 && ((uVar2 = 0x57e, param_4 != 0x57e || (uVar2 = 0x2069, param_5 != 0x2069))))))

  {

    return CONCAT71((int7)(uVar2 >> 8),1);

  }

  return uVar2 & 0xffffffffffffff00;

}




