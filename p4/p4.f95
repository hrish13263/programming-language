!Program 4: A program to calculate the shortest route when a person travels/
!visits to N cities (minimum tour problem) 
!CS 320
!Hrishikesh M cssc 2644
!Date: 11/4/2020

PROGRAM P4
        
        IMPLICIT NONE
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!Variable declarations
INTEGER :: i,count,distance,x,y,arr_pos, reader,city_cnt,dist_cnt
INTEGER :: ios,permutations,best_distance
INTEGER:: READBOUNDS
CHARACTER(20) :: filename

CHARACTER(20), ALLOCATABLE, DIMENSION(:) :: city_list
INTEGER ,ALLOCATABLE, DIMENSION(:,:) :: d_table
INTEGER, ALLOCATABLE , DIMENSION(:) :: path
INTEGER,ALLOCATABLE, DIMENSION(:) :: distances
CHARACTER(10),ALLOCATABLE,DIMENSION(:) :: city
INTEGER,ALLOCATABLE,DIMENSION (:) :: best_path
PRINT *, " Hrishikesh. M, cssc2644"
PRINT *, "Enter filename"
READ *, filename

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!Open the file and read number of cities
OPEN(UNIT=9, FILE=filename, FORM="FORMATTED", ACTION="READ",&
                                     STATUS="OLD",IOSTAT=ios)
IF(ios /= 0) THEN
    PRINT *, "Could not open the file ",TRIM(filename)," Error code: ", ios
    STOP
END IF

READ (UNIT=9, FMT=100) count
PRINT *, "Number of cities: ",count

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!Allocate memory for all needed arrays
ALLOCATE(city_list(count*count+count),STAT=ios)
IF(ios /= 0) THEN
    PRINT *, "ERROR, could not allocate memory."
    STOP
END IF

ALLOCATE(d_table(count,count))
ALLOCATE(path(count))
ALLOCATE (distances(count*count))
ALLOCATE(best_path(count))
ALLOCATE(city(count))



!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!Fill in array from data file
DO i=1, count*count+count

  READ (UNIT=9,FMT=200) city_list(i)
END DO

dist_cnt=1
DO i=1 ,count*count+count
        IF((reader-count) /= 0 .AND. i /= 1) THEN
        READ(city_list(i),*) distances(dist_cnt)
        dist_cnt = dist_cnt+1
        reader=reader+1
        ELSE
                reader=0
        END IF
END DO

!utilizing a two dimensional array to put numbers
arr_pos=1
   DO x = 1, count                       
        DO y = 1, count 
           d_table(y,x) = distances(arr_pos)
           arr_pos= arr_pos+1
        END DO 
    END DO

!Getting the names of city
city_cnt=1
DO i=1 , count
        city(i) = city_list(city_cnt)
        city_cnt = city_cnt+(count+1)
END DO


DO i=1, count
        path(i) = i
END DO

DO i=1, count
        best_path(i) = i
END DO


!Using recursion to find minimal distance, setting to large number and going
!from there
best_distance = 999999
call permute(2,count)

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!Print the formatted output
DO i=1, count
        IF(i==count) THEN
                PRINT*," ",city(best_path(i)),"to ", city(best_path(1)),"--",d_table(best_path(i),1),"miles"

        ELSE
                PRINT*," ",city(best_path(i)),"to ", city(best_path(i+1)),"--",d_table(best_path(i),best_path(i+1)),"miles"

        END IF
END DO
PRINT*
PRINT*,"Best Distance is: ",best_distance,"miles"


!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!Format labels
100 FORMAT (I6)
200 FORMAT (A)

CONTAINS
!The Permute function that was given to us which calculate the different combinations
RECURSIVE SUBROUTINE permute(first, last)
!Declare intent of parameter variable
INTEGER, INTENT(IN) :: first, last
INTEGER :: i, temp
         
        IF(first == last)  THEN
                distance = d_table(1,path(2))
                                DO i=2, last-1           
                        distance = distance + d_table(path(i),path(i+1)) 
                                        END DO
                distance = distance + d_table(path(last),path(1))
                                permutations = permutations + 1
                IF(distance < best_distance) THEN
                        best_distance = distance
                        DO i=2, count
                                best_path(i) = path(i)
                        END DO
                END IF
                
        ELSE
                DO i=first, last
                        temp = path(first)
                        path(first) = path(i)
                        path(i) = temp

                        call permute(first+1,last)
         
                        temp = path(first)
                        path(first) = path(i)
                        path(i) = temp
                        
                END DO
        END IF
        

               
END SUBROUTINE permute   


END PROGRAM P4
