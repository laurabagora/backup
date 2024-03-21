# Constants
MINCODON     = 5
MASS         = 30
UNIQUECODONS = 4
NUCLEOTIDE  = 3

# Main Function
def main():
    
    # Prints what program does
    print('This program reports information about DNA')
    print('nucletoride sequence that may encode proteins.')
    
    # Calls Function
    readfile()

# Opens file and creates new file to write in
def readfile():
    file = input('Input file name? ')
    output = input('Output file name? ')

    # Opening and splitting up the file
    with open(file) as files:
        filed = files.readlines()

    for data in filed:
        data = data.split('\n')

    # Writing in the file
    with open(output, 'w') as output:
        for index in range(0,len(filed) - 1,2):
            output.write('Region Name: ' + filed[index])            
            nuc = filed[index+1]
            output.write('Nucleotides: ' + nuc)
            outter = nuc_counts(nuc)
            inner = remove(nuc)
            output.write('Nuc. Counts: ' + str(outter[0])+ '\n')
            output.write('Total Mass%: ' + str(mass(outter)) + '\n')
            output.write('Codons List: ' + str(codon_list(inner)) + '\n')
            more = mass(outter)
            even = codon_list(more)
            output.write('Is Protein? ' + str(protein(codon_list(inner))) + '\n')
            output.write('\n')
            
    files.close()

# Calculates how many times each letter exists
def nuc_counts(nuc):
    a_count = 0
    g_count = 0
    t_count = 0
    c_count = 0
    junk = 0

    nuc = list(nuc.upper())
    for word in nuc:
        if word == 'A':
            a_count = a_count + 1
        elif word == 'C':
            c_count = c_count + 1
        elif word == 'G':
            g_count = g_count + 1
        elif word == 'T':
            t_count = t_count + 1
        else:
            junk = junk + 1

    return([a_count, c_count, g_count, t_count], junk)

# Calculates mass of each element and total mass
def mass(nuc_counts):
    a_total = nuc_counts[0][0] * 135.128
    c_total = nuc_counts[0][1] * 111.103
    g_total = nuc_counts[0][2] * 151.128
    t_total = nuc_counts[0][3] * 125.107
    j_total = nuc_counts[1] * 100.00
    
    all_total = round((a_total + c_total + g_total + t_total + j_total),1)

    # Total mass
    a_mass = round(((a_total / all_total) * 100), 1)
    c_mass = round(((c_total / all_total) * 100), 1)
    g_mass = round(((g_total / all_total) * 100), 1)
    t_mass = round(((t_total / all_total) * 100), 1)

    return(str([a_mass, c_mass, g_mass, t_mass]) + ' of ' + str(all_total))

# Removes extra characters in file
def remove(nuc):
    chars = nuc.split(', ')
    codons = []
    for char in nuc:
        if char.lower() in 'agct':
            codons.append(char)
    return ''.join(codons)

# Makes codons into an organized list
def codon_list(nuc):
    nuc = list(nuc.upper())
    cod=[nuc[index:index+NUCLEOTIDE] for index in range(0,len(nuc),NUCLEOTIDE)]
    value = 0
    grow = []

    for items in range(0, len(cod)):
        merge = ''.join(cod[value])
        cod[value] = [merge]
        value += 1
        
    for index in cod:
        for items in index:
            grow.append(items)

    return grow

    
# Shows whether it is a protein or not
def protein(nuc):
    nuc = nuc[:-2]
    # First codon, last codon, how many codons
    if (nuc[0] == "ATG"):
        if (nuc[-1] == "TAA" or "TAG" or "TGA"):
            if(len(nuc) >= MINCODON):
                return 'YES'
            else:
                return 'NO'
        else:
            return 'NO'
    else:
        return 'NO'   

# Call back to main
main()
