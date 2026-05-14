// Address: 0x1400f0bc0
// Ghidra name: FUN_1400f0bc0
// ============ 0x1400f0bc0 FUN_1400f0bc0 (size=211) ============


int FUN_1400f0bc0(char *param_1,int param_2)



{

  int iVar1;

  char *pcVar2;

  

  pcVar2 = param_1;

  iVar1 = FUN_1400f40d0();

  if (iVar1 != 0) {

    return -(uint)(param_2 != 0);

  }

  if (((((*param_1 == 't') && (param_1[1] == 't')) && (param_1[2] == 'c')) &&

      ((param_1[3] == 'f' &&

       ((iVar1 = (uint)(byte)param_1[5] * 0x10000 + (uint)(byte)param_1[6] * 0x100 +

                 (uint)(byte)param_1[4] * 0x1000000 + (uint)(byte)param_1[7], iVar1 == 0x10000 ||

        (iVar1 == 0x20000)))))) &&

     (param_2 < (int)((((uint)(byte)param_1[9] + (uint)(byte)pcVar2[8] * 0x100) * 0x100 +

                      (uint)(byte)pcVar2[10]) * 0x100 + (uint)(byte)pcVar2[0xb]))) {

    return (uint)(byte)pcVar2[(longlong)(param_2 * 0xe) + 0xd] * 0x10000 +

           (uint)(byte)pcVar2[(longlong)(param_2 * 0xe) + 0xe] * 0x100 +

           (uint)(byte)pcVar2[(longlong)(param_2 * 0xe) + 0xc] * 0x1000000 +

           (uint)(byte)pcVar2[(longlong)(param_2 * 0xe) + 0xf];

  }

  return -1;

}




