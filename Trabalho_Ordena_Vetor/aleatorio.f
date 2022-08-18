program hello
real x(10),a,b,c
integer r(10),tam
tam=10
r=aleatorio(tam)
call aleatorio1(r,tam)
print *,r
call ordena(r,tam)
print *,r
end program hello

real function aleatorio(tam)
    integer tam
    real r(tam)
    integer x(tam)
    call random_number(r)
    x=r*100
    return 
end function

subroutine aleatorio1(r,tam)
    integer tam
    integer r(tam)
    real x(tam)
    call random_number(x)
    r=x*100
    return 
end subroutine

subroutine ordena(vetor,tam)
    integer tam
    integer vetor(tam),minimo
    do i=1,tam-1
    minimo=i
    do j=i+1,tam
    IF(vetor(j)<vetor(minimo)  )THEN  
        minimo=j
    end if
    end do
    IF(i/=min  )THEN  
        aux=vetor(i)
        vetor(i)=vetor(minimo)
        vetor(minimo)=aux
    end if
end do
    return 
end subroutine
