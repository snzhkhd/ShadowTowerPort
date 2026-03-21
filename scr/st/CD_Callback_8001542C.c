#include "recomp.h"
#include "disable_warnings.h"


void CD_Callback_8001542C(uint8_t* rdram, recomp_context* ctx)
{

	printf("\n!!!!!!CD_Callback_8001542C!!!!!!!1\n");

	/*
	int stream; // $s0

  int result; // $v0

  stream = g_ActiveCdStream;

  if ( a1 == 2 )

  {

    result = *(unsigned __int8 *)g_ActiveCdStream;

    if ( *(_BYTE *)g_ActiveCdStream )

    {

      result = *(unsigned __int8 *)g_ActiveCdStream < 2u;

      if ( *(unsigned __int8 *)g_ActiveCdStream < 5u && *(unsigned __int8 *)g_ActiveCdStream >= 2u )

      {

        *(_DWORD *)(g_ActiveCdStream + 36) = 0;

LABEL_11:

        result = sub_8006BB0C(0);               // <- וסעü וש¸ 2 גûחמגא ג InitEvent ט CDInit

        *(_BYTE *)(stream + 1) = 2;

      }

    }

  }

  else

  {

    result = 5;

    if ( a1 == 5 )

    {

      result = *(unsigned __int8 *)g_ActiveCdStream;

      if ( *(_BYTE *)g_ActiveCdStream )

      {

        result = *(unsigned __int8 *)g_ActiveCdStream < 2u;

        if ( *(unsigned __int8 *)g_ActiveCdStream < 5u && *(unsigned __int8 *)g_ActiveCdStream >= 2u )

        {

          *(_DWORD *)(g_ActiveCdStream + 36) = -1;

          goto LABEL_11;

        }

      }

    }

  }

  return result;
	*/
}