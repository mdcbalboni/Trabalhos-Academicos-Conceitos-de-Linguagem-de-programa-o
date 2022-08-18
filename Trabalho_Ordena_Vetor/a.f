program hello
 integer vetor(4),aux,minimo,tam
 tam=4
do i=1,tam
    read *, vetor(i)
end do
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
do i=1,tam
    print *,vetor(i)
end do
end program hello
